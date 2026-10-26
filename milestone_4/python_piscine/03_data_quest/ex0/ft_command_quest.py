import sys

if __name__ == "__main__":
    print("=== Command Quest ===")
    print(f"Program name:  {sys.argv[0]}")

if len(sys.argv) > 1:
    print(f"Arguments received:  {len(sys.argv) - 1}")
    for i, arg in enumerate(sys.argv[1:], start=1):
        print(f"Arguments {i}:  {arg}")
else:
    print("No arguments provided!")

print(f"Total arguments: {len(sys.argv)}")
