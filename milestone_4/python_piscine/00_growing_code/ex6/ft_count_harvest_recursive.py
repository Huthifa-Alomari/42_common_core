def ft_count_harvest_recursive() -> None:
    Days = input("Days until harvest: ")
    ft_count_harvest_recursive_helper(Days)
    print("Harvest time!")


def ft_count_harvest_recursive_helper(Days):
    if int(Days) <= 0:
        return 0
    ft_count_harvest_recursive_helper(int(Days) - 1)
    print(f"Day {Days}")
    return
