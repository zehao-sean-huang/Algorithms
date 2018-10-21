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
     * Problem 5
     */
    string longestPalindrome(string s) {
        // 
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
};
