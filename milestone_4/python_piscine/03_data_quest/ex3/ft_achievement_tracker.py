import random


def gen_player_achievements(master_achievements: list[str]) -> set[str]:
    random_size = random.randint(6, 10)
    random_sample = random.sample(master_achievements, random_size)
    return set(random_sample)


def main() -> None:
    master_achievements = [
        "Crafting Genius", "World Savior", "Master Explorer",
        "Collector Supreme", "Untouchable", "Boss Slayer",
        "Strategist", "Unstoppable", "Speed Runner",
        "Survivor", "Treasure Hunter", "First Steps",
        "Sharp Mind", "Hidden Path Finder"
    ]

    names = ["Alice", "Bob", "Charlie", "Dylan"]
    players: list[tuple[str, set[str]]] = []
    for name in names:
        players.append((name, gen_player_achievements(master_achievements)))

    print("=== Achievement Tracker System ===\n")

    for name, achievements in players:
        print(f"Player {name}: {achievements}")

    all_distinct: set[str] = set()
    for _, achievements in players:
        all_distinct = all_distinct.union(achievements)

    print(f"\nAll distinct achievements: {all_distinct}")

    common_achievements = set(master_achievements)
    for _, achievements in players:
        common_achievements = common_achievements.intersection(achievements)

    print(f"\nCommon achievements: {common_achievements}\n")

    for name, achievements in players:
        other_union: set[str] = set()
        for other_name, other_achv in players:
            if other_name != name:
                other_union = other_union.union(other_achv)
        exclusive = achievements.difference(other_union)
        print(f"Only {name} has: {exclusive}")

    print("\n")
    master_set = set(master_achievements)
    for name, achievements in players:
        missing = master_set.difference(achievements)
        print(f"{name} is missing: {missing}")


if __name__ == "__main__":
    main()
