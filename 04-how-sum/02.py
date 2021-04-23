
def howSumHelper(lst, target, stk, table):
    if target in table:
        return list(table[target])

    if target == 0:
        return stk

    if target < 0:
        return []

    for num in lst:
        rem = target - num

        stk.append(num)
        if howSumHelper(lst, rem, stk, table):
            table[target] = tuple(stk)
            return stk

        stk.pop()

    table[target] = tuple()
    return []


def howSum(lst, target):
    ret = howSumHelper(lst, target, [], {})

    if not ret:
        return None

    return ret


if __name__ == '__main__':
    print(howSum([2, 3], 7))
    print(howSum([5, 3, 4, 7], 7))
    print(howSum([2, 4], 7))
    print(howSum([2, 3, 5], 8))
    print(howSum([7, 14], 300))

    # True, True, False, True, False
