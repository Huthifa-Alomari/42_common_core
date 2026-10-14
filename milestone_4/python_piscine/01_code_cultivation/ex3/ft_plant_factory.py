class Plant:
    def __init__(self, name: str, height: float, age: int):
        self.name = name
        self.height = height
        self.age = age

    def Show(self) -> None:
        print(f"Created:   {self.name}: {self.height:.1f}cm,"
              f"  {self.age} days old")

    def Grow(self) -> None:
        self.height = self.height + 0.8

    def Age(self) -> None:
        self.age = self.age + 1


if __name__ == "__main__":
    print("=== Plant Factory Output ===")
    plant1 = Plant("Rose", 25.0, 30)
    plant2 = Plant("Oak", 200.0, 365)
    plant3 = Plant("Cactus", 5.0, 90)
    plant4 = Plant("Sunflower", 80.0, 45)
    plant5 = Plant("Fern", 15.0, 120)
    plant1.Show()
    plant2.Show()
    plant3.Show()
    plant4.Show()
    plant5.Show()
