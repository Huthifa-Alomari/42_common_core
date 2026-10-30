import math


def get_player_pos() -> None:
    print("\nGet a first set of coordinates")
    OK = True
    while OK:
        try:
            coordinates = input("Enter new coordinates as floats in "
                                "format 'x,y,z': ")
            my_tuple = tuple(float(x) for x in coordinates.split(','))
            if len(my_tuple) == 3:
                print("Got a first tuple:", my_tuple)
                print(f"It includes: X={my_tuple[0]}, "
                      f"Y={my_tuple[1]}, Z={my_tuple[2]}")
                OK = False
            else:
                raise ValueError
        except ValueError:
            print("Invalid syntax")

    dist1 = math.sqrt(my_tuple[0]**2 + my_tuple[1]**2 + my_tuple[2]**2)
    print(f"Distance to center: {dist1:.4f}")

    OK = True
    print("\nGet a second set of coordinates")
    while OK:
        try:
            coordinates = input("Enter new coordinates as floats "
                                "in format 'x,y,z': ")
            parts = coordinates.split(',')
            if len(parts) != 3:
                raise ValueError("Invalid syntax")

            for p in parts:
                try:
                    float(p)
                except ValueError:
                    raise ValueError(f"could not convert string to float: "
                                     f"`{p.strip()}`")

            my_tuple2 = tuple(float(x) for x in parts)
            OK = False
        except ValueError as e:
            err_param = "syntax"
            for p in coordinates.split(','):
                try:
                    float(p)
                except ValueError:
                    err_param = p.strip()
                    break

            if "could not convert" in str(e):
                print(f"Error on parameter `{err_param}`: {e}")
            else:
                print("Invalid syntax")

    dist2 = math.sqrt((my_tuple2[0]-my_tuple[0])**2 + 
                      (my_tuple2[1]-my_tuple[1])**2 + 
                      (my_tuple2[2]-my_tuple[2])**2)
    print(f"Distance between the 2 sets of coordinates: {dist2:.4f}")


if __name__ == "__main__":
    print("=== Game Coordinate System ===")
    get_player_pos()
