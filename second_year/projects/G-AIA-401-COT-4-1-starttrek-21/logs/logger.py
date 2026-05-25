import csv
import os

FIELDNAMES = ["episode", "total_return", "episode_length", "termination_reason"]
DQN_FIELDNAMES = ["episode", "total_return", "episode_length", "termination_reason", "loss", "epsilon"]


def init_logger(path="logs/baseline.csv"):
    os.makedirs("logs", exist_ok=True)
    f = open(path, "w", newline="")
    fieldnames = DQN_FIELDNAMES if "dqn" in path else FIELDNAMES
    writer = csv.DictWriter(f, fieldnames=fieldnames)
    writer.writeheader()
    return f, writer


def log_episode(writer, episode, total_return, length, reason, loss=None, epsilon=None):
    row = {
        "episode": episode,
        "total_return": round(total_return, 3),
        "episode_length": length,
        "termination_reason": reason
    }
    if loss is not None:
        row["loss"] = round(loss, 6)
    if epsilon is not None:
        row["epsilon"] = round(epsilon, 4)
    writer.writerow(row)
