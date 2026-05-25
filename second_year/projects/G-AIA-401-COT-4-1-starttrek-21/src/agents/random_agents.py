##
## EPITECH PROJECT, 2026
## G-AIA-401-COT-4-1-starttrek-21
## File description:
## random_agents
##


#import gymnasium as gym

def random_policy(obs, env):
   return env.action_space.sample()
