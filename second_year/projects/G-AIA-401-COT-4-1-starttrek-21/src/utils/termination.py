
def get_termination_reason(obs, terminated, truncated):
   if truncated:
       return "timeout"
   if not terminated:
       return "running"
   x, y = obs[0], obs[1]
   if abs(x) > 1.0 or y > 1.5:
       return "out-of-view"
   # les deux jambes au sol = sleep (atterri sans crash)
   left_leg, right_leg = obs[6], obs[7]
   if left_leg and right_leg:
       return "sleep"
   return "crash"