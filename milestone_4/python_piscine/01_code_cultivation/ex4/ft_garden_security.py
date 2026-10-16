class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self._height = 0.0
        self._age = 0
        self.set_height(height)
        self.set_age(age)

    def show(self) -> None:
        print(f"Plant created: {self.name}: {self._height:.1f}cm, "
              f"{self._age} days old")

    def set_height(self, nheight: float) -> None:
        if nheight < 0:
            print(f"{self.name}: Error, height can't be negative")
            print("Height update rejected")
        else:
            self._height = nheight
            print(f"Height updated: {self._height}cm")

    def set_age(self, nage: int) -> None:
        if nage < 0:
            print(f"{self.name}: Error, age can't be negative")
            print("Age update rejected")
        else:
            self._age = nage
            print(f"Age updated: {self._age} days")

    def get_height(self) -> float:
        return self._height

    def get_age(self) -> int:
        return self._age


if __name__ == "__main__":
    print("=== Garden Security System ===")
    plant = Plant("Rose", 25.0, 30)
    plant.show()

    plant.set_height(33.2)
    plant.set_age(2)

    plant.set_height(-33.2)
    plant.set_age(-2)

    print(f"\nCurrent state: {plant.name}: {plant.get_height()}cm, "
          f"{plant.get_age()} days old")
