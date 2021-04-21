
def getWays(x, y, table={}):
    if x == y == 1:
        return 1

    if x == 0 or y == 0:
        return 0

    # Accessing memoized data, and since ways(2, 3) == ways(3, 2) storing them in ascending order
    if (min(x, y), max(x, y)) in table:
        return table[(min(x, y), max(x, y))]

    ways = 0

    # Up
    ways += getWays(x-1, y, table)

    # Left
    ways += getWays(x, y-1, table)

    # Memoizing
    table[(min(x, y), max(x, y))] = ways

    return ways


if __name__ == '__main__':
    print(getWays(1, 1))
    print(getWays(2, 3))
    print(getWays(3, 2))
    print(getWays(3, 3))
    print(getWays(18, 18))  # Voila works here
