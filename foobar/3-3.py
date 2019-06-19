dp = {}

def helper(n):
    x = n
    if x in dp:
        return dp[x]
    result = 0
    while n % 2 == 0:
        n //= 2
        result += 1
    if n > 1:
        result += min(helper(n + 1), helper(n - 1)) + 1
    dp[x] = result
    return dp[x]

def solution(n):
    # convert the string to the digit.
    dp[0] = 0
    dp[1] = 0
    dp[2] = 1
    dp[3] = 2
    dp[4] = 2
    n = int(n)
    return helper(n)
