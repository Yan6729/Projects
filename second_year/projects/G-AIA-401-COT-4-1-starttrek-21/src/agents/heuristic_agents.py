##
## EPITECH PROJECT, 2026
## G-AIA-401-COT-4-1-starttrek-21
## File description:
## heuristic_agents
##


def heuristic_policy(obs):
   x, y, vx, vy, theta, theta_dot, left_leg, right_leg = obs

   # Les deux jambes au sol → ne rien faire
   if left_leg and right_leg:
       return 0  # do nothing

   # Trop incliné à gauche → propulseur droit
   if theta > 0.3:
       return 3  # fire right thruster

   # Trop incliné à droite → propulseur gauche
   if theta < -0.3:
       return 1  # fire left thruster

   # Chute trop rapide → moteur principal
   if vy < -0.5:
       return 2  # fire main engine

   return 0