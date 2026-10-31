import random
from typing import Generator


def gen_event(players: list[str],
              actions: list[str]) -> Generator[tuple[str, str], None, None]:
    while True:
        yield (random.choice(players), random.choice(actions))


def consume_event(
    events: list[tuple[str, str]]
) -> Generator[tuple[str, str], None, None]:
    while events:
        index = random.randint(0, len(events) - 1)
        yield events.pop(index)


def main() -> None:
    print("=== Game Data Stream Processor ===")

    players = ["alice", "bob", "charlie", "dylan"]
    actions = ["run", "eat", "sleep", "grab",
               "move", "climb", "swim", "release"]

    stream = gen_event(players, actions)

    for i in range(1000):
        player, action = next(stream)
        print(f"Event {i}: Player {player} did action {action}")

    event_list = []
    for _ in range(10):
        event_list.append(next(stream))
    print(f"Built list of 10 events: {event_list}")

    for event in consume_event(event_list):
        print(f"Got event from list: {event}")
        print(f"Remains in list: {event_list}")


if __name__ == "__main__":
    main()
