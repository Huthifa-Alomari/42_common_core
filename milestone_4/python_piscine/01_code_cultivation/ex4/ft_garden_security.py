class Plant:
    def __init__(self, name: str, height: float, age: int):
        self.name = name
        self.height = height
        self.age = age

    def Show(self) -> None:
        print(f"Plant created:  {self.name}:    "
              f"{self.height:.1f}cm,    {self.age} days old")

    def set_heigh(self, nheight: float):
        if nheight < 0:
            print(f"{self.name}: Error, height can`t be negative")
            print("Height update rejected")
        else:
            self.height = nheight
            print(f"Height updated: {self.height}")

    def set_age(self, nage: int):
        if nage < 0:
            print(f"{self.name}: Error, age can`t be negative")
            print("Age update rejected")
        else:
            self.age = nage
            print(f"Age updated: {self.age}")

    def get_heigh(self) -> float:
        return self.height

    def get_age(self) -> int:
        return self.age


if __name__ == "__main__":
    print("=== Garden Security System ===")
    plant = Plant("Rose", 25.0, 30)
    plant.Show()

    plant.set_heigh(33.2)
    plant.set_age(2)

    plant.set_heigh(-33.2)
    plant.set_age(-2)

    print(f"\nCurrent state:  {plant.name}:   {plant.height}cm,"
          f"  {plant.age} days old")
