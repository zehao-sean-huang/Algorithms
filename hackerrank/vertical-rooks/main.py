#!/bin/python3

import os
import sys

#
# Complete the verticalRooks function below.
#
def verticalRooks(r1, r2):
    value_range = lambda a: 0 if a == 1 else (1 if a == 2 else 2)
    move = [value_range(abs(m[0] - m[1])) for m in zip(r1, r2)]
    stats = [move.count(0), move.count(1), move.count(2)]
    return 'player-1' if sum(map(lambda x: x % 2, stats)) == 0 else 'player-2'

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        n = int(input())

        r1 = []

        for _ in range(n):
            r1_item = int(input())
            r1.append(r1_item)

        r2 = []

        for _ in range(n):
            r2_item = int(input())
            r2.append(r2_item)

        result = verticalRooks(r1, r2)

        fptr.write(result + '\n')

    fptr.close()

