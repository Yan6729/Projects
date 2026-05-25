import gymnasium as gym

# Création de l'environnement
env = gym.make("LunarLander-v3", render_mode="human")
observation, info = env.reset()

for _ in range(100):
    # On prend une action au hasard (P1 : c'est ta baseline !)
    action = env.action_space.sample() 
    observation, reward, terminated, truncated, info = env.step(action)

    if terminated or truncated:
        observation, info = env.reset()

env.close()
print("L'installation fonctionne parfaitement !")
