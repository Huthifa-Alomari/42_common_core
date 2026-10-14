class Plant:
    def __init__(self, name: str, height: float, age: int):
        self.name = name
        self.height = height
        self.age = age

    def Show(self) -> None:
        print(f"{self.name}: {self.height:.1f}cm, {self.age} days old")

    def Grow(self) -> None:
        self.height = self.height + 0.8

    def Age(self) -> None:
        self.age = self.age + 1


if __name__ == "__main__":
    print("=== Garden Plant Growth ===")
    plant = Plant("Rose", 25, 30)
    init_height = plant.height
    plant.Show()
    for i in range(1, 8):
        plant.Grow()
        plant.Age()
        print(f"=== Day {i} ===")
        print(f"{plant.name}: {plant.height:.1f}cm, {plant.age} days old")
    print(f"Growth this week: {plant.height - init_height:.1f}cm")
