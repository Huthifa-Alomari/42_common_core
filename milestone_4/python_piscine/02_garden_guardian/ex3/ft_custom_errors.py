class GardenError(Exception):
    def __init__(self, message: str = "A garden error occurred.") -> None:
        super().__init__(message)


class PlantError(GardenError):
    def __init__(self, message: str = "The tomato plant is wilting!") -> None:
        super().__init__(message)


class WaterError(GardenError):
    def __init__(self, message: str = "Not enough water in the tank!") -> None:
        super().__init__(message)


def check_plant() -> None:
    raise PlantError()


def check_water() -> None:
    raise WaterError()


if __name__ == "__main__":
    print("=== Custom Garden Errors Demo ===\n")

    print("Testing PlantError...")
    try:
        check_plant()
    except PlantError as e:
        print(f"Caught PlantError: {e}\n")

    print("Testing WaterError...")
    try:
        check_water()
    except WaterError as e:
        print(f"Caught WaterError: {e}\n")

    print("Testing catching all garden errors...")
    try:
        check_plant()
    except GardenError as e:
        print(f"Caught GardenError: {e}")

    try:
        check_water()
    except GardenError as e:
        print(f"Caught GardenError: {e}\n")

    print("All custom error types work correctly!")
