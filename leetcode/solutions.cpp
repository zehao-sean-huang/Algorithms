#include <bits/stdc++.h>

using namespace std;

class Solution {

    public:
    
    /**
     * Problem 1
     */ 
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    vector<int> result({i, j});
                    return result;
                }
            }
        }
    }

    /**
     * Problem 32
     */
    int longestValidParentheses(string s) {
        
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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
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
    int minPathSum(vector<vector<int>>& grid) {
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
};
