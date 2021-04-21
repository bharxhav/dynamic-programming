
def fib(n):
    table = [0, 1]

    for i in range(2, n+1):
        table.append(table[i-1] + table[i-2])

    return table[n]


print(fib(4))
print(fib(5))
print(fib(6))
print(fib(50))  # Now we wont have stackoverflow, and also neednot pass the table
