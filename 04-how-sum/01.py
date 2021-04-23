# In this problem, we take a target, and return a combination of numbers array.
# Return the operands which sum to target.


def howSumHelper(lst, target, stk):
    if target == 0:
        return stk

    if target < 0:
        return None

    for num in lst:
        rem = target - num

        stk.append(num)
        if howSumHelper(lst, rem, stk):
            return stk

        stk.pop()

    return None


def howSum(lst, target):
    return howSumHelper(lst, target, [])


if __name__ == '__main__':
    print(howSum([2, 3], 7))
    print(howSum([5, 3, 4, 7], 7))
    print(howSum([2, 4], 7))
    print(howSum([2, 3, 5], 8))
    print(howSum([7, 14], 300))

    # True, True, False, True, False
