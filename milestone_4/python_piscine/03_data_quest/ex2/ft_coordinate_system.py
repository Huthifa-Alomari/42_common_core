import math

def get_player_pos() -> tuple:
    print("Get a first set of coordinates")

    while(True):
        try:
            x1: float = input()
            y1: float = input()
            z1: float = input()

            print(f"Enter new coordinates as floats in format "
                  f"’x,y,z’: {x1:.1f}{y1:.1f}{z1:.1f}")

        except ValueError:
            print("Invalid syntax")


    print("Get a second set of coordinates")



    print(f"Distance between the 2 sets of coordinates:"
          f"{math.sqrt((x2-x1)**2 + (y2-y1)**2 + (z2-z1)**2)}")



if __name__ == "__main__":
    print("=== Player Score Analytics ===")
    get_player_pos()

