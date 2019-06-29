result = 0

def factorial(n):
    return 1 if n < 2 else n * factorial(n - 1)

binomial = lambda n, r: factorial(n) // factorial(r) // factorial(n - r)

for n in range(23, 101):
    for r in range(3, n // 2 + 1):
        if binomial(n, r) > 1000000:
            t = n - 2 * r + 1
            print(n, r, t)
            result += t
            break

print(result)
