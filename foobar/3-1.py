cache = {} # cache[(b,p)] = helper(b,p)

def helper(bricks, previous):
    # returns the cached result if exists
    if bricks <= 0:
        return 0
    if previous < 2:
        return 0
    if (bricks, previous) in cache:
        return cache[(bricks, previous)]
    result = 1 if bricks < previous else 0
    for i in range(int((2 * bricks) ** 0.5), previous):
        result += helper(bricks - i, i)
    cache[(bricks, previous)] = result
    return result
    
def solution(n):
    # Your code here
    result = 0
    for i in range(int((2 * n) ** 0.5), n):
        result += helper(n - i, i)
    return result
