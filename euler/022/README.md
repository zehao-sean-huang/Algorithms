# Project Euler 022

What is the total of all the name scores in the file?

# main.cpp

Standard C++ solution

# main.py

A one-line, fast solution in python3.

```python
print(sum([(index + 1) * sum([ord(char) - ord('A') + 1 for char in name]) for index, name in enumerate(sorted([name[1:-1] for name in open("main.in").read().split(",")]))]))
```