# Project Euler 016

What is the sum of the digits of the number 2^1000?

## main.cpp

Standard C++ solution. Large number addition emulated using strings.

## main.py

A one-line, fast solution since python automatically handles large numbers.

```python
print(sum([int(char) for char in str(2 ** 1000)]))
```
