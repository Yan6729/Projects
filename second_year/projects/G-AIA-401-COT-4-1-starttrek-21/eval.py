##
## EPITECH PROJECT, 2026
## G-AIA-401-COT-4-1-starttrek-21
## File description:
## eval
##

import argparse

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Evaluate a trained model")
    parser.add_argument("--model", type=str, help="Path to model checkpoint")
    parser.add_argument("--episodes", type=int, default=100, help="Number of evaluation episodes")
    args = parser.parse_args()
    print(f"Evaluation: model={args.model}, episodes={args.episodes}")

