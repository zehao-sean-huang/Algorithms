from math import factorial
from collections import Counter
from fractions import gcd

def count(c, n):
    result = factorial(n)
    for a, b in Counter(c).items():
        result //= factorial(b) * (a ** b)
    return result

# simplify enumerations of all possibilities to enumerations of cycles. 
def partitions(n, i = 1):
    yield [n]
    for i in range(i, n // 2 + 1):
        for partition in partitions(n - i, i):
            yield [i] + partition

def solution(w, h, s):
    result = 0
    for a in partitions(w):
        for b in partitions(h):
            m = count(a, w) * count(b, h) # multiplier in the formula of each possible partition
            result += m * (s ** sum([sum([gcd(i, j) for i in a]) for j in b]))
    return result // factorial(w) // factorial(h)
