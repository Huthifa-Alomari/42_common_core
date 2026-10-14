class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age

    def show(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.age} days old")


class Flower(Plant):
    def __init__(self, name: str, height: float,
                 age: int, color: str, at_bloom: bool) -> None:
        super().__init__(name, height, age)
        self.color = color
        self.at_bloom = at_bloom

    def show(self) -> None:
        super().show()
        print(f"Color:   {self.color}")
        self.bloom()

    def bloom(self):
        if self.at_bloom is True:
            print("Rose is blooming beautifully!")
        else:
            print("Rose has not bloomed yet")


class Tree(Plant):
    def __init__(self, name: str, height: float,
                 age: int, trunk_diameter: float) -> None:
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter

    def show(self) -> None:
        super().show()
        print(f"Trunk diameter: {self.trunk_diameter}")

    def produce_shade(self) -> None:
        print(f"Tree Oak now produces a shade of {self.height}cm "
              f"long and {self.trunk_diameter}cm wide.")


class Vegetable(Plant):
    def __init__(self, name: str, height: float, age: int,
                 harvest_season: str, nutritional_value: int) -> None:
        super().__init__(name, height, age)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value

    def show(self) -> None:
        super().show()
        print(f"Harvest season: {self.harvest_season}")
        print(f"Nutritional Value: {self.nutritional_value}")


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

    print("[make tomato grow and age for 20 days")
    Tvegetable = Vegetable("Tomoto", 47.0, 30, "April", 20)
    Tvegetable.show()
