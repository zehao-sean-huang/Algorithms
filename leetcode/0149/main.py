from fractions import Fraction
import statistics
from collections import Counter


def maxPoints(points):
    n = len(points)
    if n < 2:
        return n
    result = 0
    for i in range(n):
        slopes = []
        # choose a base point
        x = points[i][0]
        y = points[i][1]
        # then calculate slope from this point to other points
        repeat = 1
        for j in range(i + 1, n):
            if x == points[j][0] and y == points[j][1]:
                repeat += 1
            elif y == points[j][1]:
                slopes.append(float('inf'))
            else:
                slopes.append(Fraction(x - points[j][0], y - points[j][1])) 
        # max occurrence of a certain slope
        result = max(result, (Counter(slopes).most_common()[0][1] if len(slopes) else 0) + repeat)
        # pause if exhausted
        if (n - i - 1) <= result: 
            break
    return result


if __name__ == "__main__":
    with open('main.in') as f:
        m = int(f.readline())
        for i in range(m):
            points = eval(f.readline())
            print(maxPoints(points))
