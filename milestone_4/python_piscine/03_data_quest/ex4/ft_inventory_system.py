import sys


def main() -> None:
    print("=== Inventory System Analysis ===")
    inventory = {}

    for arg in sys.argv[1:]:
        if ":" not in arg:
            print(f"Error - invalid parameter '{arg}'")
            continue

        item, qty_str = arg.split(":", 1)

        if item in inventory:
            print(f"Redundant item '{item}' - discarding")
            continue

        try:
            qty = int(qty_str)
            inventory[item] = qty
        except ValueError as e:
            print(f"Quantity error for '{item}': {e}")

    print(f"Got inventory: {inventory}")

    items = list(inventory.keys())
    print(f"Item list: {items}")

    total_qty = sum(inventory.values())
    print(f"Total quantity of the {len(items)} items: {total_qty}")

    if total_qty > 0:
        for item, qty in inventory.items():
            pct = round((qty / total_qty) * 100, 1)
            print(f"Item {item} represents {pct}%")

    if inventory:
        most_item = items[0]
        least_item = items[0]
        for item, qty in inventory.items():
            if qty > inventory[most_item]:
                most_item = item
            if qty < inventory[least_item]:
                least_item = item

        print(f"Item most abundant: {most_item} with quantity "
              f"{inventory[most_item]}")
        print(f"Item least abundant: {least_item} with quantity "
              f"{inventory[least_item]}")

    inventory.update({"magic_item": 1})
    print(f"Updated inventory: {inventory}")


if __name__ == "__main__":
    main()
