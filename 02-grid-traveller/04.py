

def getWays(x, y):
    # Generalising to a triangular array
    x, y = max(x, y), min(x, y)

    # Similar to Fibonacci 03, using bottom up technique, and More efficient in space compared to 03 in grid in most of the cases
    table = []

    # Creating the matrix
    for i in range(x):
        table.append([0] * (i+1))

    for i in range(x):
        for j in range(i+1):
            if i == 0 or j == 0:
                table[i][j] = 1
                continue

            if i == j:
                table[i][j] = 2 * table[max(i-1, j)][min(i-1, j)]
                continue

            table[i][j] = table[i-1][j] + table[i][j-1]

    return table[x-1][y-1]


if __name__ == '__main__':
    print(getWays(1, 1))
    print(getWays(2, 3))
    print(getWays(3, 2))
    print(getWays(3, 3))
    print(getWays(18, 18))

    # Specific testcase
    print(getWays(16, 18))  # 565722720
