class Plant:
    def __init__(self, name: str, height: float, age: int):
        self.name = name
        self.height = height
        self.age = age

    def show(self) -> None:
        print(f"{self.name}: {self.height:.1f}cm, {self.ft_age} days old")

    def grow(self) -> None:
        self.height = self.height + 0.8

    def ft_age(self) -> None:
        self.age = self.age + 1


if __name__ == "__main__":
    print("=== Garden Plant growth ===")
    plant = Plant("Rose", 25, 30)
    init_height = plant.height
    plant.show()
    for i in range(1, 8):
        plant.grow()
        plant.ft_age()
        print(f"=== Day {i} ===")
        print(f"{plant.name}: {plant.height:.1f}cm, {plant.age} days old")
    print(f"growth this week: {plant.height - init_height:.1f}cm")
