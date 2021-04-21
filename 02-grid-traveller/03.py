

def getWays(x, y):
    # Similar to Fibonacci 03, using bottom up technique
    table = []

    # Creating the matrix
    for _ in range(x):
        table.append([0] * y)

    for i in range(x):
        for j in range(y):
            if i == 0 or j == 0:
                table[i][j] = 1
                continue

            table[i][j] = table[i-1][j] + table[i][j-1]

    return table[x-1][y-1]


if __name__ == '__main__':
    print(getWays(1, 1))
    print(getWays(2, 3))
    print(getWays(3, 2))
    print(getWays(3, 3))
    print(getWays(18, 18))
