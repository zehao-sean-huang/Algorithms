#include <bits/stdc++.h>

using namespace std;

class Solution {

    public:
    
    /**
     * util functions
     */
    void printVector(vector<int>& v) {
        if (v.empty()) {
            cout << "<empty vector>" << endl;
        } else {
            for (int i : v) {
                cout << i << " ";
            }
        }
        cout << endl;
    }

    /**
     * Problem 1
     */ 
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
    }

    /**
     * Problem 5
     * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
     * 
     * Example 1:
     * Input: "babad"
     * Output: "bab"
     * Note: "aba" is also a valid answer.
     * 
     * Example 2:
     * Input: "cbbd"
     * Output: "bb"
     */
    string longestPalindrome(string s) {
        bool result[1010][1010]; // result[start][end]
        int rs = 0, re = 0;
        memset(result, true, sizeof(result));
        for (int i = 0; i < s.size(); ++i) {
            result[i][i] = true;
            for (int start = i - 1; start >= 0; --start) {
                int length = i - start + 1;
                result[start][i] = (s[start] == s[i] && result[start + 1][i - 1]);
                if (result[start][i] && length > (re - rs + 1)) {
                    rs = start; re = i;
                }
            }
        }
        return s.substr(rs, (re - rs + 1));
    }

    /**
     * Problem 10
     * Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
     * '.' Matches any single character.
     * '*' Matches zero or more of the preceding element.
     * The matching should cover the entire input string (not partial).
     * 
     * Note:
     * 
     * s could be empty and contains only lowercase letters a-z.
     * p could be empty and contains only lowercase letters a-z, and characters like . or *.
     * 
     */

    bool isMatch(string s, string p) {
        // base cases
        if (s.empty() && p.empty()) {
            return true;
        } else if (s.empty()) {
            if (p.size() == 1) {
                return false;
            } else {
                return p[1] == '*' && isMatch(s, p.substr(2));
            }
        } else if (p.empty()) {
            return false;
        } else if (p.size() == 1) {
            return (s.size() == 1) && (p[0] == '.' ? true : p[0] == s[0]);
        }
        // recursive cases
        if (p[1] == '*') {
            if (p[0] == '.') {
                bool result = false;
                for (int i = 0; i <= s.size(); ++i) {
                    result = result || isMatch(s.substr(i), p.substr(2));
                }
                return result;
            } else {
                bool result = isMatch(s.substr(0), p.substr(2));
                int index = 0;
                while (s[index] == p[0]) {
                    result = result || isMatch(s.substr(index + 1), p.substr(2));
                    index++;
                } 
                return result;
            }
        } else {
            if (p[0] == '.') {
                return isMatch(s.substr(1), p.substr(1));
            } else {
                return p[0] == s[0] && isMatch(s.substr(1), p.substr(1));
            }
        }
    }

    /**
     * Problem 32
     * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
     * 
     * Example 1:
     * 
     * Input: "(()"
     * Output: 2
     * Explanation: The longest valid parentheses substring is "()"
     * Example 2:
     * 
     * Input: ")()())"
     * Output: 4
     * Explanation: The longest valid parentheses substring is "()()"
     */
    int longestValidParentheses(string s) {
        int maxr = 0;
        int r[100010];
        memset(r, 0, sizeof(r));
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    r[i] = i >= 2 ? r[i - 2] + 2 : 2;
                } else if (s[i - r[i - 1] - 1] == '(') {
                    r[i] = r[i - 1] + ((i - r[i - 1]) >= 2 ? r[i - r[i - 1] - 2] : 0) + 2;
                }
                maxr = max(maxr, r[i]);
            }
        }
        return maxr;
    }

    /**
     * Problem 44
     * Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.
     * 
     * '?' Matches any single character.
     * '*' Matches any sequence of characters (including the empty sequence).
     * The matching should cover the entire input string (not partial).
     * 
     * Note:
     * 
     * s could be empty and contains only lowercase letters a-z.
     * p could be empty and contains only lowercase letters a-z, and characters like ? or *.
     */
    bool isMatchWildcard(string s, string p) {
        if (p.empty()) {
            return s.empty();
        }
        bool r[s.size() + 1][p.size() + 1];
        memset(r, false, sizeof(r));
        r[0][0] = true;
        for (int j = 1; j <= p.size(); ++j) {
            if (p[j - 1] == '*') {
                r[0][j] = r[0][j - 1];
            }
        }
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 1; j <= p.size(); ++j) {
                if (p[j - 1] == '*') { // be sure to understand why only r[i - 1][j]
                    r[i][j] = r[i][j - 1] || r[i - 1][j];
                } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    r[i][j] = r[i - 1][j - 1];
                } else {
                    r[i][j] = false;
                }
            }
        }
        return r[s.size()][p.size()];
    }

    /**
     * Problem 53
     * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
     * Example:
     * 
     * Input: [-2,1,-3,4,-1,2,1,-5,4],
     * Output: 6
     * Explanation: [4,-1,2,1] has the largest sum = 6.
     * Follow up:
     * 
     * If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
     */
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        } else if (nums.size() == 1) {
            return nums[0];
        } else {
            int mid = nums.size() / 2;
            vector<int> left(nums.begin(), nums.begin() + mid);
            vector<int> right(nums.begin() + mid, nums.end());
            int rl = maxSubArray(left);
            int rr = maxSubArray(right);
            int ltm = INT_MIN, rtm = INT_MIN, ls = 0, rs = 0;
            for (int i = left.size() - 1; i >= 0; --i) {
                ls += left[i];
                ltm = max(ltm, ls);
            }
            for (int i = 0; i < right.size(); ++i) {
                rs += right[i];
                rtm = max(rtm, rs);
            }
            return max(ltm + rtm, max(rl, rr));
        }
    }
    
    /**
     * Problem 62
     */
    int uniquePaths(int m, int n) {
        int result[110][110];
        memset(result, 0, sizeof(result));
        result[0][1] = 1;
        for (int r = 1; r <= m; ++r) {
            for (int c = 1; c <= n; ++c) {
                result[r][c] = result[r][c - 1] + result[r - 1][c];
            }
        }
        return result[m][n];
    }

    /**
     * Problem 63
     */
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int result[110][110];
        memset(result, 0, sizeof(result));
        result[0][1] = 1;
        for (int r = 0; r < obstacleGrid.size(); ++r) {
            for (int c = 0; c < obstacleGrid[r].size(); ++c) {
                if (obstacleGrid[r][c]) {
                    result[r + 1][c + 1] = 0;
                } else {
                    result[r + 1][c + 1] = result[r][c + 1] + result[r + 1][c];
                }
            }
        }
        return result[obstacleGrid.size()][obstacleGrid[0].size()];
    }

    /**
     * Problem 64
     */
    int minPathSum(vector<vector<int> >& grid) {
        int result[1010][1010];
        memset(result, INT_MAX, sizeof(result));
        result[0][1] = result[1][0] = grid[0][0];
        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[r].size(); ++c) {
                if (r == 0 && c == 0) {
                    result[r][c] = grid[r][c];
                } else if (r == 0) {
                    result[r][c] = grid[r][c] + result[r][c - 1];
                } else if (c == 0) {
                    result[r][c] = grid[r][c] + result[r - 1][c];
                } else {
                    result[r][c] = grid[r][c] + min(result[r][c - 1], result[r - 1][c]);
                }
            }
        }
        return result[grid.size() - 1][grid[0].size() - 1];
    }

    /**
     * Problem 70
     */
    map<int, int> computed;
    int climbStairs(int n) {
        if (n == 1 || n == 2) {
            return n;
        } else if (computed.find(n) == computed.end()) {
            computed[n] = climbStairs(n - 1) + climbStairs(n - 2);
        } 
        return computed[n];
    }

    /**
     * Problem 72
     * Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
     * 
     * You have the following 3 operations permitted on a word:
     * 
     * Insert a character
     * Delete a character
     * Replace a character
     */
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int r[m + 1][n + 1];
        memset(r, 0, sizeof(r));
        for (int j = 0; j <= n; ++j) {
            r[0][j] = j;
        }
        for (int i = 1; i <= m; ++i) {
            r[i][0] = i;
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    r[i][j] = r[i - 1][j - 1];
                } else {
                    r[i][j] = 1 + min(r[i - 1][j - 1], min(r[i - 1][j], r[i][j - 1]));
                }
            }
        }
        return r[m][n];
    }
};
