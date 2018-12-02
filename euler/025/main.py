#!/usr/local/bin/python3

previous = 1
current = 1
index = 2

while len(str(current)) < 1000:
    previous, current = current, current + previous
    index += 1

print(index)