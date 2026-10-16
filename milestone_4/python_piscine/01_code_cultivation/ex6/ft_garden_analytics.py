class Plant:
    class _Stats:
        def __init__(self) -> None:
            self._grow_count: int = 0
            self._age_count: int = 0
            self._show_count: int = 0

        def increment_grow(self) -> None:
            self._grow_count += 1

        def increment_age(self) -> None:
            self._age_count += 1

        def increment_show(self) -> None:
            self._show_count += 1

        def display(self) -> None:
            print(
                f"Stats: {self._grow_count} grow, "
                f"{self._age_count} age, "
                f"{self._show_count} show"
            )

    def __init__(self, name: str, height: float, age: int) -> None:
        self.name: str = name
        self._height: float = 0.0
        self._age: int = 0
        self.set_height(height)
        self.set_age(age)
        self._stats = self._Stats()

    @staticmethod
    def is_older_than_year(days: int) -> bool:
        return days > 365

    @classmethod
    def create_anonymous(cls) -> "Plant":
        return cls("Unknown plant", 0.0, 0)

    def get_height(self) -> float:
        return self._height

    def set_height(self, height: float) -> None:
        if height < 0:
            print("Error: Height cannot be negative.")
        else:
            self._height = float(height)

    def get_age(self) -> int:
        return self._age

    def set_age(self, age: int) -> None:
        if age < 0:
            print("Error: Age cannot be negative.")
        else:
            self._age = int(age)

    def grow(self, amount: float) -> None:
        if amount > 0:
            self.set_height(self.get_height() + amount)
            self._stats.increment_grow()

    def age(self, days: int) -> None:
        if days > 0:
            self.set_age(self.get_age() + days)
            self._stats.increment_age()

    def show(self) -> None:
        self._stats.increment_show()
        print(f"{self.name}: {self.get_height():.1f}cm, "
              f"{self.get_age()} days old")


class Flower(Plant):
    def __init__(
        self,
        name: str,
        height: float,
        age: int,
        color: str,
        at_bloom: bool
    ) -> None:
        super().__init__(name, height, age)
        self.color: str = color
        self.at_bloom: bool = at_bloom

    def show(self) -> None:
        super().show()
        print(f"Color: {self.color}")
        self.bloom()

    def bloom(self) -> None:
        if self.at_bloom:
            print(f"{self.name} is blooming beautifully!")
        else:
            print(f"{self.name} has not bloomed yet")


class Seed(Flower):
    def __init__(
        self,
        name: str,
        height: float,
        age: int,
        color: str,
        at_bloom: bool,
        seed_count: int = 0,
    ) -> None:
        super().__init__(name, height, age, color, at_bloom)
        self._seed_count: int = seed_count

    def show(self) -> None:
        super().show()
        seeds = self._seed_count if self.at_bloom else 0
        print(f"Seeds: {seeds}")


class Tree(Plant):
    class _Stats(Plant._Stats):
        def __init__(self) -> None:
            super().__init__()
            self._shade_count: int = 0

        def increment_shade(self) -> None:
            self._shade_count += 1

        def display(self) -> None:
            super().display()
            print(f"{self._shade_count} shade")

    def __init__(
        self, name: str, height: float, age: int, trunk_diameter: float
    ) -> None:
        super().__init__(name, height, age)
        self.trunk_diameter: float = trunk_diameter
        self._stats: Tree._Stats = self._Stats()

    def show(self) -> None:
        super().show()
        print(f"Trunk diameter: {self.trunk_diameter:.1f}cm")

    def produce_shade(self) -> None:
        self._stats.increment_shade()
        print(
            f"Tree {self.name} now produces a shade of "
            f"{self.get_height():.1f}cm long and "
            f"{self.trunk_diameter:.1f}cm wide."
        )


def display_plant_statistics(plant: Plant) -> None:
    print(f"[statistics for {plant.name}]")
    plant._stats.display()


if __name__ == "__main__":
    print("=== Garden statistics ===")
    print("=== Check year-old")
    print(f"Is 30 days more than a year? -> {Plant.is_older_than_year(30)}")
    print(f"Is 400 days more than a year? -> {Plant.is_older_than_year(400)}")

    print("\n=== Flower")
    rose = Flower("Rose", 15.0, 10, "red", False)
    rose.show()
    display_plant_statistics(rose)

    print("[asking the rose to grow and bloom]")
    rose.grow(8.0)
    rose.at_bloom = True
    rose.show()
    display_plant_statistics(rose)

    print("\n=== Tree")
    oak = Tree("Oak", 200.0, 365, 5.0)
    oak.show()
    display_plant_statistics(oak)

    print("[asking the oak to produce shade]")
    oak.produce_shade()
    display_plant_statistics(oak)

    print("\n=== Seed")
    sunflower = Seed("Sunflower", 80.0, 45, "yellow", False, 42)
    sunflower.show()

    print("[make sunflower grow, age and bloom]")
    sunflower.grow(30.0)
    sunflower.age(20)
    sunflower.at_bloom = True
    sunflower.show()
    display_plant_statistics(sunflower)

    print("\n=== Anonymous")
    anon = Plant.create_anonymous()
    anon.show()
    display_plant_statistics(anon)
