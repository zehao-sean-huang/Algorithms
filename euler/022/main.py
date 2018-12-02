#!/usr/local/bin/python3

print(sum([(index + 1) * sum([ord(char) - ord('A') + 1 for char in name]) for index, name in enumerate(sorted([name[1:-1] for name in open("main.in").read().split(",")]))]))
    