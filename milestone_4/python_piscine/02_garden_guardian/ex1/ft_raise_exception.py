def input_temperature(temp_str: str) -> int:
    a = int(temp_str)
    if a > 40:
        raise ValueError(f" {a} is too hot for plants (max 40°C)")
    elif a < 0:
        raise ValueError(f" {a} is too cold for plants (min 0°C)")

    return a


def test_temperature(temp_str: str) -> None:
    print(f"\nInput data is ’{temp_str}’")
    try:
        a = input_temperature(temp_str)
        print(f"Temperature is now {a}°C")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")


if __name__ == "__main__":
    print("=== Garden Temperature Checker ===")

    test_temperature("25")
    test_temperature("abc")
    test_temperature("100")
    test_temperature("-50")

    print("\nAll tests completed - program didn`t crash!")
