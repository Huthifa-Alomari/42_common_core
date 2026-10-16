#!/usr/bin/env python3
class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self._name = name
        self._height = height
        self._age = age

    def show(self) -> None:
        print(f"{self._name}: {self._height:.1f}cm, {self._age} days old")

    def grow(self, amount: float = 1.0) -> None:
        self._height += amount

    def age(self, days: int = 1) -> None:
        self._age += days


class Flower(Plant):
    def __init__(self, name: str, height: float,
                 age: int, color: str, at_bloom: bool) -> None:
        super().__init__(name, height, age)
        self._color = color
        self._at_bloom = at_bloom

    def show(self) -> None:
        super().show()
        print(f"Color: {self._color}")
        if self._at_bloom:
            print(f"{self._name} is blooming beautifully!")
        else:
            print(f"{self._name} has not bloomed yet")

    def bloom(self) -> None:
        self._at_bloom = True


class Tree(Plant):
    def __init__(self, name: str, height: float,
                 age: int, trunk_diameter: float) -> None:
        super().__init__(name, height, age)
        self._trunk_diameter = trunk_diameter

    def show(self) -> None:
        super().show()
        print(f"Trunk diameter: {self._trunk_diameter:.1f}cm")

    def produce_shade(self) -> None:
        print(f"Tree {self._name} now produces a shade of "
              f"{self._height:.1f}cm "
              f"long and {self._trunk_diameter:.1f}cm wide.")


class Vegetable(Plant):
    def __init__(self, name: str, height: float, age: int,
                 harvest_season: str, nutritional_value: float) -> None:
        super().__init__(name, height, age)
        self._harvest_season = harvest_season
        self._nutritional_value = nutritional_value

    def show(self) -> None:
        super().show()
        print(f"Harvest season: {self._harvest_season}")
        print(f"Nutritional value: {round(self._nutritional_value)}")

    def grow(self, amount: float = 1.0) -> None:
        super().grow(amount)
        self._nutritional_value += .5

    def age(self, days: int = 1) -> None:
        super().age(days)
        self._nutritional_value += .5


if __name__ == "__main__":
    print("=== Garden Plant Types ===")

    print("=== Flower")
    Rflower = Flower("Rose", 15.0, 10, "red", False)
    Rflower.show()

    print("[asking the rose to bloom]")
    Rflower.bloom()
    Rflower.show()

    print("\n=== Tree")
    Otree = Tree("Oak", 200.0, 365, 5.0)
    Otree.show()
    print("[asking the oak to produce shade]")
    Otree.produce_shade()

    print("\n=== Vegetable")
    Tvegetable = Vegetable("Tomato", 5.0, 10, "April", 0)
    Tvegetable.show()

    print("[make tomato grow and age for 20 days]")
    for i in range(20):
        Tvegetable.grow(2.1)
        Tvegetable.age(1)
    Tvegetable.show()
