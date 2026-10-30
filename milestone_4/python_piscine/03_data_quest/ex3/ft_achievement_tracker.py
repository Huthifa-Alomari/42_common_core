import random

MASTER_ACHIEVEMENTS = [
    "Crafting Genius", "World Savior", "Master Explorer", "Collector Supreme",
    "Untouchable", "Boss Slayer", "Strategist", "Unstoppable", "Speed Runner",
    "Survivor", "Treasure Hunter", "First Steps",
    "Sharp Mind", "Hidden Path Finder"
]

if __name__ == "__main__":
    players = {}
    for name in ["Alice", "Bob", "Charlie", "Dylan"]:

        random_size = random.randint(3, len(MASTER_ACHIEVEMENTS))
        random_sample = random.sample(MASTER_ACHIEVEMENTS, random_size)
        achievement_set = set(random_sample)
        players[name] = achievement_set

    print("=== Achievement Tracker System ===\n")

    for name, achievements in players.items():
        print(f"Player {name}: {achievements}")

    all_distinct = set.union(*players.values())

    print(f"\nAll distinct achievements: {all_distinct}")

    common_achievements = set.intersection(*players.values())

    print(f"\nCommon achievements: {common_achievements}\n")

    counts: dict[str, int] = {}
    for achievements in players.values():
        for achv in achievements:
            counts[achv] = counts.get(achv, 0) + 1

    for name, achievements in players.items():
        exclusive = {achv for achv in achievements if counts[achv] == 1}
        print(f"Only {name} has: {exclusive}")

    print("\n")
    for name, achievements in players.items():
        missing = all_distinct - achievements
        print(f"{name} is missing: {missing}")
