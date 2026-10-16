#!/usr/bin/env python3
class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self._height = 0.0
        self._age = 0
        if height < 0:
            print(f"{self.name}: Error, height can't be negative")
            print("Height update rejected")
        else:
            self._height = float(height)

        if age < 0:
            print(f"{self.name}: Error, age can't be negative")
            print("Age update rejected")
        else:
            self._age = int(age)

    def show(self) -> None:
        print(f"Plant created: {self.name}: {self._height:.1f}cm, "
              f"{self._age} days old\n")

    def set_height(self, nheight: float) -> None:
        if nheight < 0:
            print(f"{self.name}: Error, height can't be negative")
            print("Height update rejected")
        else:
            self._height = float(nheight)
            h_str = int(nheight) if nheight == int(nheight) else nheight
            print(f"Height updated: {h_str}cm")

    def set_age(self, nage: int) -> None:
        if nage < 0:
            print(f"{self.name}: Error, age can't be negative")
            print("Age update rejected\n")
        else:
            self._age = int(nage)
            print(f"Age updated: {self._age} days\n")

    def get_height(self) -> float:
        return self._height

    def get_age(self) -> int:
        return self._age


if __name__ == "__main__":
    print("=== Garden Security System ===")
    plant = Plant("Rose", 15.0, 10)
    plant.show()

    plant.set_height(25)
    plant.set_age(30)

    plant.set_height(-25)
    plant.set_age(-30)

    print(f"Current state: {plant.name}: {plant.get_height():.1f}cm, "
          f"{plant.get_age()} days old")
