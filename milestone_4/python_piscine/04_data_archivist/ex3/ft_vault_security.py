import os


def secure_archive(filename, action="read", content=""):
    if action == "read":
        try:
            with open(filename, "r") as file:
                return True, file.read()
        except Exception as e:
            return False, str(e)

    elif action == "write":
        try:
            with open(filename, "w") as file:
                file.write(content)
                return True, "Content successfully written to file"
        except Exception as e:
            return False, str(e)

    return False, f"Invalid action: {action}"


if __name__ == "__main__":
    print("=== Cyber Archives Security ===")

    print("\nUsing ’secure_archive’ to read from a nonexistent file:")
    print(secure_archive("/not/existing/file", "read"))

    print("\nUsing ’secure_archive’ to read from an inaccessible file:")
    print(secure_archive("/etc/master.passwd", "read"))

    demo_file = "archive_fragment.txt"
    demo_content = (
        "[FRAGMENT 001] Digital preservation protocols established 2087\n"
        "[FRAGMENT 002] Knowledge must survive the entropy wars\n"
        "[FRAGMENT 003] Every byte saved is a victory against oblivion\n"
    )

    with open(demo_file, "w") as f:
        f.write(demo_content)

    print("\nUsing ’secure_archive’ to read from a regular file:")
    print(secure_archive(demo_file, "read"))

    print("\nUsing ’secure_archive’ to write previous content to a new file:")
    print(secure_archive("output_vault.txt", "write", demo_content))

    if os.path.exists(demo_file):
        os.remove(demo_file)
    if os.path.exists("output_vault.txt"):
        os.remove("output_vault.txt")
