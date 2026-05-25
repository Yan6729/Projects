import gymnasium as gym
import os
import datetime
from gymnasium.wrappers import RecordVideo

def record_episodes(config, agent_type, policy_fn, n_episodes=3):
   """
   Enregistre n_episodes épisodes en vidéo.
   Les vidéos sont sauvegardées dans videos/{agent_type}_{timestamp}/
   """
   timestamp = datetime.datetime.now().strftime('%Y%m%d_%H%M%S')
   video_dir = f"videos/{agent_type}_{timestamp}"
   os.makedirs(video_dir, exist_ok=True)

   # RecordVideo wrappe l'env et capte les frames automatiquement
   env = gym.make(config["env"]["name"], render_mode="rgb_array")
   env = RecordVideo(
       env,
       video_folder=video_dir,
       episode_trigger=lambda ep: ep < n_episodes  # enregistre les n premiers
   )
   for ep in range(n_episodes):
       obs, _ = env.reset(seed=config["run"]["seed"] + ep)
       while True:
           action = policy_fn(obs) if agent_type == "heuristic" else env.action_space.sample()
           obs, _, terminated, truncated, _ = env.step(action)
           if terminated or truncated:
               break

   env.close()
   print(f"Vidéos sauvegardées dans {video_dir}/")