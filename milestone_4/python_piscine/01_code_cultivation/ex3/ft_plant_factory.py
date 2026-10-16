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
    print("=== Plant Factory Output ===")
    plant1 = Plant("Rose", 25.0, 30)
    plant2 = Plant("Oak", 200.0, 365)
    plant3 = Plant("Cactus", 5.0, 90)
    plant4 = Plant("Sunflower", 80.0, 45)
    plant5 = Plant("Fern", 15.0, 120)
    for plant in [plant1, plant2, plant3, plant4, plant5]:
        print("Created: ", end="")
        plant.show()
