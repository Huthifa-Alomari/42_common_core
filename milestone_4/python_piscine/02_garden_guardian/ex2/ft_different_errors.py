def garden_operations(operation_number: int) -> None:
    if operation_number == 0:
        int("abd")
    elif operation_number == 1:
        10 / 0
    elif operation_number == 2:
        open("test.txt")
    elif operation_number == 3:
        "abc" + 10
    else:
        return


def test_error_types() -> None:
    print("=== Garden Error Types Demo ===")
    for i in (0, 1, 2, 3, 4):
        print(f"Testing operation {i}")
        try:
            garden_operations(i)
        except ValueError as e:
            print(f"Caught ValueError: {e}")
        except ZeroDivisionError as e:
            print(f"Caught ZeroDivisionError: {e}")
        except FileNotFoundError as e:
            print(f"Caught FileNotFoundError: {e}")
        except TypeError as e:
            print(f"Caught TypeError: {e}")

    print("Operation completed successfully")
    print("\nAll error types tested successfully!")


if __name__ == "__main__":
    test_error_types()
