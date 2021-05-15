
def bestSumHelper(lst, target, stk, f):
    if target in f:
        return f[target]

    if target < 0:
        return None

    if target == 0:
        return []

    ret = None
    for num in lst:
        stk.append(num)
        ans = bestSumHelper(lst, target - num, stk[:], f)

        if ans != None:
            tmp = ans + [num]

            if not ret or len(tmp) < len(ret):
                ret = tmp[:]

        stk.pop()

    f[target] = ret
    return ret


def bestSum(lst, target):
    f = {}
    ret = bestSumHelper(lst, target, [], f)

    if len(ret) == 0:
        print("No Possible Combination.")
        return

    print("Shortest Possible Combination is : ")
    print(*ret)


if __name__ == '__main__':
    bestSum([5, 3, 4, 7], 7)
    bestSum([2, 3, 5], 8)
    bestSum([1, 4, 5], 8)
    bestSum([1, 2, 5, 25], 100)
