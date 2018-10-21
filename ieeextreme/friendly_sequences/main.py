#!/usr/local/bin/python3

# try recursion

line1, line2 = input(), input()

n = int(line1)
l = list([int(item) for item in line2.split(' ')])

def recur(i):
    result = 0
    if (i == len(l) - 1):
        return l[i] + 1
    first_max = min([value // (index + 1) for index, value in enumerate(l[i:])])
    for first in range(first_max):
        result += recur(i + 1)
        for j in range(i, len(l)):
            l[i] -= (j + 1)
    result += recur(i + 1)
    for j in range (i, len(l)):
        l[i] += first_max * (j + 1)
    return result

print(recur(0))