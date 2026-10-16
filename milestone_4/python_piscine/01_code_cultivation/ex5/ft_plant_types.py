class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self._name = name
        self._height = height
        self._age = age

    def show(self) -> None:
        print(f"{self._name}: {self._height}cm, {self._age} days old")


class Flower(Plant):
    def __init__(self, name: str, height: float,
                 age: int, color: str, at_bloom: bool) -> None:
        super().__init__(name, height, age)
        self._color = color
        self._at_bloom = at_bloom

    def show(self) -> None:
        super().show()
        print(f"Color: {self._color}")
        self.bloom()

    def bloom(self) -> None:
        if self._at_bloom:
            print(f"{self._name} is blooming beautifully!")
        else:
            print(f"{self._name} has not bloomed yet")


class Tree(Plant):
    def __init__(self, name: str, height: float,
                 age: int, trunk_diameter: float) -> None:
        super().__init__(name, height, age)
        self._trunk_diameter = trunk_diameter

    def show(self) -> None:
        super().show()
        print(f"Trunk diameter: {self._trunk_diameter}cm")

    def produce_shade(self) -> None:
        print(f"Tree Oak now produces a shade of {self._height}cm "
              f"long and {self._trunk_diameter}cm wide.")


class Vegetable(Plant):
    def __init__(self, name: str, height: float, age: int,
                 harvest_season: str, nutritional_value: int) -> None:
        super().__init__(name, height, age)
        self._harvest_season = harvest_season
        self._nutritional_value = nutritional_value

    def show(self) -> None:
        super().show()
        print(f"Harvest season: {self._harvest_season}")
        print(f"Nutritional Value: {self._nutritional_value}")


if __name__ == "__main__":
    print("=== Garden Plant Types ===")

    print("=== Flower")
    Rflower = Flower("Rose", 25.0, 10, "red", False)
    Rflower.show()

    print("[asking the rose to bloom]")
    Rflower = Flower("Rose", 25.0, 10, "red", True)
    Rflower.show()

    print("\n=== Tree")
    Otree = Tree("Oak", 200.0, 365, 5.0)
    Otree.show()
    print("[asking the oak to produce shade]")
    Otree.produce_shade()

    print("\n=== Vegetable")
    Tvegetable = Vegetable("Tomoto", 5.0, 10, "April", 0)
    Tvegetable.show()

    print("[make tomato grow and age for 20 days]")
    Tvegetable = Vegetable("Tomoto", 47.0, 30, "April", 20)
    Tvegetable.show()
