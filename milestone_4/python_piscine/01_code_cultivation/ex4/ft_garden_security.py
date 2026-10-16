class Plant:
    def __init__(self, name: str, height: float, age: int):
        self._name = name
        self._height = height
        self._age = age

    def Show(self) -> None:
        print(f"Plant created: {self._name}: {self._height:.1f}cm, "
              f"{self._age} days old")

    def set_heigh(self, nheight: float):
        if nheight < 0:
            print(f"{self._name}: Error, height can't be negative")
            print("Height update rejected")
        else:
            self._height = nheight
            print(f"Height updated: {self._height}")

    def set_age(self, nage: int):
        if nage < 0:
            print(f"{self._name}: Error, age can't be negative")
            print("Age update rejected")
        else:
            self._age = nage
            print(f"Age updated: {self._age}")

    def get_heigh(self) -> float:
        return self._height

    def get_age(self) -> int:
        return self._age


if __name__ == "__main__":
    print("=== Garden Security System ===")
    plant = Plant("Rose", 25.0, 30)
    plant.Show()

    plant.set_heigh(33.2)
    plant.set_age(2)

    plant.set_heigh(-33.2)
    plant.set_age(-2)

    print(f"\nCurrent state: {plant._name}: {plant.get_heigh()}cm, "
          f"{plant.get_age()} days old")
