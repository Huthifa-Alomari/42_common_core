#!/usr/bin/env python3
class Plant:
    def __init__(self, name: str, height: float, _age: int) -> None:
        self.name = name
        self.height = height
        self._age = _age

    def show(self) -> None:
        print(f"{self.name}: {self.height:.1f}cm, {self._age} days old")

    def grow(self) -> None:
        self.height = self.height + 0.8

    def age(self) -> None:
        self._age = self._age + 1


if __name__ == "__main__":
    print("=== Garden Plant Growth ===")
    plant = Plant("Rose", 25, 30)
    init_height = plant.height
    plant.show()
    for i in range(1, 8):
        plant.grow()
        plant.age()
        print(f"=== Day {i} ===")
        print(f"{plant.name}: {plant.height:.1f}cm, {plant._age} days old")
    print(f"Growth this week: {plant.height - init_height:.1f}cm")
