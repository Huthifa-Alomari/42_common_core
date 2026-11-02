import sys


def main():
    if len(sys.argv) < 2:
        print("Usage: ft_ancient_text.py <file>")
        return

    filename = sys.argv[1]
    print("=== Cyber Archives Recovery ===")
    print(f"Accessing file '{filename}'")

    try:
        with open(filename, 'r') as f:
            print("---\n")
            print(f.read(), end='')
            print("\n---")
            print(f"File '{filename}' closed.")
    except Exception as e:
        print(f"Error opening file '{filename}': {e}")


if __name__ == "__main__":
    main()
