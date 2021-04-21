
def getWays(x, y):
    if x <= 0:
        return 0

    if y <= 0:
        return 0

    ways = 0

    # Up
    ways += getWays(x-1, y)

    # Left
    ways += getWays(x, y-1)

    # Reached the destination
    if x == y == 1:
        return 1

    return ways


if __name__ == '__main__':

    print(getWays(1, 0))
    print(getWays(0, 1))
    print(getWays(1, 1))
    print(getWays(3, 3))
    print(getWays(2, 2))
