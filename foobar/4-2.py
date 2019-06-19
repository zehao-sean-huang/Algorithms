def factorial(n):
    """
    Compute the factorial of n
    >>> factorial(0)
    1
    >>> factorial(1)
    1
    >>> factorial(2)
    2
    >>> factorial(3)
    6
    """
    return 1 if n < 2 else n * factorial(n - 1)

def binomial(n, m):
    """
    Select m items from n items without repetition.
    >>> binomial(2, 0)
    1
    >>> binomial(5, 3)
    10
    >>> binomial(4, 3)
    4
    """
    return factorial(n) // factorial(m) // factorial(n - m)

def combinations(lst, m):
    """
    Recursive implementation of generator of combinations of m items from lst w/o repetition.
    """
    if m == 0:
        yield ()
    if m > 0:
        if len(lst) == m:
            yield tuple(lst)
        if len(lst) > m:
            for combination in combinations(lst[1:], m - 1):
                yield combination + tuple(lst[:1])
            for combination in combinations(lst[1:], m):
                yield combination

def solution(num_buns, num_required):
    """
    The keys held by each minion can be represented as a binary string of length n, where the ith 
    bit is 0 if the minion doesn't have that key, and 1 otherwise. The OR value of any combination
    of num_required bit strings should be "1...111"; the OR value of any combination of less than 
    num_required bit strings should not be "1...111". The total number of bit strings is num_buns. 
    The length of all bitstrings, n, should be minimized. 

    Think from the opposite perspective, for any combination of num_required - 1 bit strings, for 
    at least one entry, the values of all bit strings in that entry should be 0. For that particular
    entry, no other bit string can take the value 0, or we can construct a combination of num_required
    bit strings such that their OR value is not "1...111". So for a particular entry, only at most
    num_required - 1 bit strings can take the value 0. To minimize the length of bit strings, there 
    are totally binomial(num_buns, num_required - 1) combinations of num_required - 1 bit strings, so 
    at least we need binomial(num_buns, num_required - 1) keys to accomplish the scheme.

    Then we iterate through the combinations. For each combination we set the corresponding entry to 0
    >>> solution(2, 1)
    [[0], [0]]
    >>> solution(5, 3)
    [[0, 1, 2, 3, 4, 5], [0, 1, 2, 6, 7, 8], [0, 3, 4, 6, 7, 9], [1, 3, 5, 6, 8, 9], [2, 4, 5, 7, 8, 9]]
    >>> solution(4, 4)
    [[0], [1], [2], [3]]
    """
    length = binomial(num_buns, num_required - 1)
    strings = [[1 for _ in range(length)] for _ in range(num_buns)]
    for i, combination in enumerate(combinations(list(range(num_buns)), num_required - 1)):
        for j in combination:
            strings[j][length - i - 1] = 0
    result = []
    for string in strings:
        result.append([i for i, j in enumerate(string) if j])
    return result
