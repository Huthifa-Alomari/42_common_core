import sys


def main():
    if len(sys.argv) < 2:
        print("Usage: ft_ancient_text.py <file>")
        return

    filename = sys.argv[1]
    print("=== Cyber Archives Recovery & Preservation ===")
    print(f"Accessing file '{filename}'")

    try:
        with open(filename, 'r') as f:
            print("---\n")
            print(f.read(), end='')
            print("\n---")
            print(f"File '{filename}' closed.\n")

        print("Transform data:")
        print("---\n")

        transformed_lines = []
        with open(filename, 'r') as f:
            for line in f:
                modified_line = line.rstrip('\n') + "#"
                transformed_lines.append(modified_line)
                print(modified_line)
        print("\n---")

        new_filename = input("Enter new file name (or empty): ").strip()

        if new_filename:
            with open(new_filename, 'w') as f_out:
                f_out.write("\n".join(transformed_lines) + "\n")
            print(f"Data saved in file '{new_filename}'")
        else:
            print("Not saving data")

    except Exception as e:
        print(f"Error opening file '{filename}': {e}")


if __name__ == "__main__":
    main()
