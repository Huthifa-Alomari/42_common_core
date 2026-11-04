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

        print("Enter new file name (or empty): ", end="")
        sys.stdout.flush()

        raw_input = sys.stdin.readline()

        if len(raw_input) > 0 and raw_input[len(raw_input) - 1] == '\n':
            new_filename = raw_input[:-1]
        else:
            new_filename = raw_input

        if new_filename:
            print(f"Saving data to '{new_filename}'")
            try:
                with open(new_filename, 'w') as f_out:
                    f_out.write("\n".join(transformed_lines) + "\n")
                print(f"Data saved in file '{new_filename}'")
            except Exception as write_error:
                sys.stderr.write(f"[STDERR] Error opening file '"
                                 f"{new_filename}': {write_error}\n")
                sys.stderr.flush()
                print("Data not saved.")
        else:
            print("Data not saved.")

    except Exception as e:
        sys.stderr.write(f"[STDERR] Error opening file '{filename}': {e}\n")
        sys.stderr.flush()


if __name__ == "__main__":
    main()
