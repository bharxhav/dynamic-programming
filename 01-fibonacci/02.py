
def fib(n, table={}):
    if n in table:
        return table[n]

    # Since default value of table is null
    if n < 2:
        return n

    k = fib(n-1) + fib(n-2)

    table[n] = k
    return k


print(fib(4))
print(fib(5))
print(fib(6))
print(fib(50))  # Pretty fast, but fails not soo efficient in stack space
