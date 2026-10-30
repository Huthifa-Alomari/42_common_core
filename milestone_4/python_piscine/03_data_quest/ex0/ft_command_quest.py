import sys


def main():
    print("=== Command Quest ===")
    print(f"Program name: {sys.argv[0]}")

    args = sys.argv[1:]
    num_args = len(args)

    if num_args == 0:
        print("No arguments provided!")
    else:
        print(f"Arguments received: {num_args}")
        for i, arg in enumerate(args, start=1):
            print(f"Argument {i}: {arg}")

    print(f"Total arguments: {len(sys.argv)}")


if __name__ == "__main__":
    main()
