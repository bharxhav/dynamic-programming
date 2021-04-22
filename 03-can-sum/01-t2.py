

def canSum(lst, target):
    if target == 0:
        return True

    for num in lst:
        rem = target - num

        if rem < 0:
            continue

        if canSum(lst, rem):
            return True

    return False


if __name__ == '__main__':
    print(canSum([2, 3], 7))
    print(canSum([5, 3, 4, 7], 7))
    print(canSum([2, 4], 7))
    print(canSum([2, 3, 5], 8))
    print(canSum([7, 14], 300))

    # True, True, False, True, False


# In this solution, we are bruteforcing more than necessary.
# Since we are iterating over and over, it takes more time.
