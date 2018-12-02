#!/usr/local/bin/python3

ans = 1
for i in range(1, 101):
    ans *= i

print(ans)
print(sum([int(char) for char in str(ans)]))
