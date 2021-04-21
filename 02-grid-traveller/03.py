

def getWays(x, y):
    # Similar to Fibonacci 03, using bottom up technique
    table = []

    # Adding first base case
    table.append([1] * y)

    # Creating the matrix
    for _ in range(x-1):
        table.append([0] * y)

    # Adding base case, which is that the rows with 1, only have 1 way, to follow that path
    for i in range(x):
        table[i][0] = 1

    for i in range(1, x):
        for j in range(1, y):
            table[i][j] = table[i-1][j] + table[i][j-1]

    return table[x-1][y-1]


if __name__ == '__main__':
    print(getWays(1, 1))
    print(getWays(2, 3))
    print(getWays(3, 2))
    print(getWays(3, 3))
    print(getWays(18, 18))
