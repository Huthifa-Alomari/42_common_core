class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age

    def show(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.age} days old")

    def Grow(self) -> None:
        self.height = self.height + 0.8

    def Age(self) -> None:
        self.age = self.age + 1

    @staticmethod
    def checks(age: int) -> None:
        if age > 365:
            print("True")
        else:
            print("False")


    @classmethod
    def anonymous(cls):
        # todo
        pass

    class Calls:
        def __init__(self) -> None:
            pass
    #  todo

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


class Seed(Flower):
    def __init__(self, name: str, height: float, age: int,
                 color: str, at_bloom: bool, seed: int) -> None:
        super().__init__(name, height, age, color, at_bloom)
        self.seed = seed

    def show(self) -> None:
        super().show()
        if self.seed > 0:
            print("Sunflower has not bloomed yet")
        else:
            print("Sunflower is blooming beautifully!")


if __name__ == "__main__":
    print("=== Garden statistics ===")
    print("=== Check year-old")

    print("Is 30 days more than a year? -> ",end="")
    Flower.checks(30)
    print("Is 400 days more than a year? -> ",end="")
    Flower.checks(400)

    print("\n=== Flower")

    Rflower = Flower("Rose", 25.0, 10, "red", False)
    Rflower.show()
    print("[statistics for Rose]")

    Rflower = Flower("Rose", 25.0, 10, "red", True)
    Rflower.show()

    print("\n=== Tree")

    Otree = Tree("Oak", 200.0, 365, 5.0)
    Otree.show()
    print("[asking the oak to produce shade]")
    Otree.produce_shade()

    print("\n=== Seed")


    print("\n=== Anonymous")


