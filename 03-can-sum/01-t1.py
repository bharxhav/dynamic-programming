# Given a list of numbers, given that we can use any number any number of times.
# Implement a DP solution to find if that number can be obtained or not.

def canSum(lst, target, i=0):
    if target == 0:
        return True

    if target < 0:
        return False

    if i >= len(lst):
        return False

    return canSum(lst, target-lst[i], i) or canSum(lst, target, i+1) or canSum(lst, target-lst[i], i+1)


if __name__ == '__main__':
    print(canSum([2, 3], 7))
    print(canSum([5, 3, 4, 7], 7))
    print(canSum([2, 4], 7))
    print(canSum([2, 3, 5], 8))
    print(canSum([7, 14], 300))

    # True, True, False, True, False


# This method uses index in the function definition itself.
