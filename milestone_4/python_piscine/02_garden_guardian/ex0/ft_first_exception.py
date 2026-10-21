def input_temperature(temp_str: str) -> int:
    a = int(temp_str)
    return a


def test_temperature(temp_str: str) -> None:
    print(f"\nInput data is `{temp_str}`")
    try:
        a = input_temperature(temp_str)
        print(f"Temperature is now {a}°C")
    except ValueError:
        print(f"Caught input_temperature error: invalid literal "
              f"for int() with base 10: `{temp_str}`")


if __name__ == "__main__":
    print("=== Garden Temperature ===")

    test_temperature("25")
    test_temperature("abc")

    print("\nAll tests completed - program didn`t crash!")
