import random


def main() -> None:
    print("=== Game Data Alchemist ===")

    players = [
        'Alice', 'bob', 'Charlie', 'dylan',
        'Emma', 'Gregory', 'john', 'kevin', 'Liam'
    ]
    print(f"Initial list of players: {players}")

    all_cap = [name.capitalize() for name in players]
    print(f"New list with all names capitalized: {all_cap}")

    cap_only = [name for name in players if name == name.capitalize()]
    print(f"New list of capitalized names only: {cap_only}")

    scores = {name: random.randint(1, 1000) for name in all_cap}
    print(f"Score dict: {scores}")

    avg_score = sum(scores.values()) / len(scores)
    print(f"Score average is {round(avg_score, 2)}")

    high_scores = {k: v for k, v in scores.items() if v > avg_score}
    print(f"High scores: {high_scores}")


if __name__ == "__main__":
    main()
