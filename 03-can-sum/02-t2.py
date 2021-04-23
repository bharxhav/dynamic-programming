
def canSumHelper(lst, target, table):
    if target in table:
        return table[target]

    if target == 0:
        return True

    if target < 0:
        return False

    for num in lst:
        rem = target - num

        if canSumHelper(lst, rem, table):
            table[rem] = True
            table[target] = True
            return True

    table[target] = False
    return False


def canSum(lst, target):
    """
    # Had to put in this function
    # Python is caching previous function call's table, thus givin True to all answers
    # So had to put in this, since {} was no more just empty dictionary, it was same for all calls

    NOTE: It would have also happened in grid traveller and fibonacci, and ACTUALLY HAPPENED
          Since grid traveller and fibonacci are subsets of each other, it didn't matter there.
          It gave the right answer. Thus here, the lists are not correlated, thus giving wrong answers.
    """

    return canSumHelper(lst, target, {})


if __name__ == '__main__':
    print(canSum([2, 3], 7))
    print(canSum([5, 3, 4, 7], 7))
    print(canSum([2, 4], 7))
    print(canSum([2, 3, 5], 8))
    print(canSum([7, 14], 300))

    # True, True, False, True, False
