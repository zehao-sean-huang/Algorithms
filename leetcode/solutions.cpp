#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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
     * Problem 2
     * 
     * You are given two non-empty linked lists representing two non-negative integers. 
     * The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
     * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
     */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode *p = l1, *q = l2, *curr = dummyHead;
        int carry = 0;
        while (p != nullptr || q != nullptr) {
            int x = (p != nullptr) ? p->val : 0;
            int y = (q != nullptr) ? q->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            if (p != nullptr) p = p->next;
            if (q != nullptr) q = q->next;
        }
        if (carry > 0) {
            curr->next = new ListNode(carry);
        }
        return dummyHead->next;
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

    /**
     * Problem 87
     * Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
     */
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        bool r[n + 1][n + 1][n + 1]; // len, start1, start2
        memset(r, false, sizeof(r));
        memset(r[0], true, sizeof(r[0]));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                r[1][i][j] = (s1[i] == s2[j]);
            }
        }
        for (int l = 2; l <= n; ++l) {
            for (int b1 = 0; b1 <= n - l; ++b1) {
                for (int b2 = 0; b2 <= n - l; ++b2) {
                    for (int left = 1; left <= l - 1; ++left) {
                        if ((r[left][b1][b2] && r[l - left][b1 + left][b2 + left]) || 
                            (r[left][b1][b2 + l - left] && r[l - left][b1 + left][b2])) {
                            r[l][b1][b2] = true;
                            break;
                        }
                    }
                }
            }
        }
        return r[n][0][0];
    }

    /**
     * Problem 91
     * A message containing letters from A-Z is being encoded to numbers using the following mapping.
     * 
     * 'A' -> 1
     * 'B' -> 2
     * ...
     * 'Z' -> 26
     * Given a non-empty string containing only digits, determine the total number of ways to decode it.
     */
    int numDecodings(string s) {
        int n = s.size();
        int r[n + 1];
        memset(r, 0, sizeof(r));
        r[0] = 1;
        r[1] = s[0] != '0';
        for (int i = 2; i <= n; ++i) {
            int d = int(s[i - 1] - 48);
            int e = int(s[i - 2] - 48);
            if (d != 0) {
                r[i] += r[i - 1];
            }
            if (e != 0 && 10 * e + d <= 26) {
                r[i] += r[i - 2];
            }
        }
        return r[n]; 
    }

    /**
     * Problem 94
     * Given a binary tree, return the inorder traversal of its nodes' values.
     */
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> r;
        if (root != nullptr) {
            vector<int> left = inorderTraversal(root->left);
            vector<int> right = inorderTraversal(root->right);
            r.insert(r.end(), left.begin(), left.end());
            r.push_back(root->val);
            r.insert(r.end(), right.begin(), right.end());
        }
        return r;
    }

    /**
     * Problem 95
     * Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.
     */
    vector<TreeNode*> generateTreesHelper(int start, int end) {
        vector<TreeNode*> r;
        if (start > end) {
            r.push_back(nullptr);
        } else if (start == end) {
            TreeNode* t = new TreeNode(start);
            r.push_back(t);
        } else {
            vector<TreeNode*> left;
            vector<TreeNode*> right;
            for (int i = start; i <= end; ++i) {
                left = generateTreesHelper(start, i - 1);
                right = generateTreesHelper(i + 1, end);
                for (TreeNode* ln : left) {
                    for (TreeNode* rn : right) {
                        TreeNode* root = new TreeNode(i);
                        root->left = ln;
                        root->right = rn;
                        r.push_back(root);
                    }
                }
            }
        }
        return r;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            vector<TreeNode*> r;
            return r;
        }
        return generateTreesHelper(1, n);
    }

    /**
     * Problem 96
     * Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
     */
    int numTrees(int n) {
        int r[n + 5];
        r[0] = 0;
        r[1] = 1;
        r[2] = 2;
        for (int i = 3; i <= n; ++i) {
            r[i] = 2 * r[i - 1];
            for (int left = 1; left <= i - 2; ++left) {
                r[i] += r[left] * r[i - left - 1];
            }
        }
        return r[n];
    }

    /**
     * Problem 97
     * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
     */
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        } else {
            int m = s1.size(), n = s2.size();
            bool r[m + 5][n + 5];
            memset(r, false, sizeof(r));
            r[0][0] = true;
            for (int i = 1; i <= m; ++i) {
                r[i][0] = (s1[i - 1] == s3[i - 1]) && r[i - 1][0];
            }
            for (int j = 1; j <= n; ++j) {
                r[0][j] = (s2[j - 1] == s3[j - 1]) && r[0][j - 1];
            }
            for (int i = 1; i <= m; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (r[i - 1][j] && s1[i - 1] == s3[i + j - 1]) {
                        r[i][j] = true;
                    }
                    if (r[i][j - 1] && s2[j - 1] == s3[i + j - 1]) {
                        r[i][j] = true;
                    }
                }
            }
            return r[m][n];
        }
    }

    /**
     * Problem 98
     * Given a binary tree, determine if it is a valid binary search tree (BST).
     *
     * Assume a BST is defined as follows:
     *
     * The left subtree of a node contains only nodes with keys less than the node's key.
     * The right subtree of a node contains only nodes with keys greater than the node's key.
     * Both the left and right subtrees must also be binary search trees.
     */
    bool isValidBST(TreeNode* root, long long min, long long max) {
        if (root == nullptr) {
            return true;
        }
        if (root->val >= max || root->val <= min) {
            return false;
        }
        return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
    }
    
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }

    /**
     * Problem 115
     * Given a string S and a string T, count the number of distinct subsequences of S which equals T.
     * 
     * A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
     */
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        int r[m + 5][n + 5];
        memset(r, 0, sizeof(r));
        for (int i = 0; i <= m; ++i) {
            r[i][0] = 1;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= min(i, n); ++j) {
                r[i][j] = r[i - 1][j];
                if (s[i - 1] == t[j - 1]) {
                    r[i][j] += r[i - 1][j - 1];
                }
            }
        }
        return r[m][n];
    }

    /**
     * Problem 120
     * Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
     */
    int minimumTotal(vector<vector<int> >& triangle) {
        if (triangle.empty()) {
            return 0;
        }
        int n = triangle.size();
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < i; ++j) {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }

    /**
     * Problem 121
     * Say you have an array for which the ith element is the price of a given stock on day i.
     * If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
     * Note that you cannot sell a stock before you buy one.
     */
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), maxp = 0;
        int search[n + 10];
        memset(search, -1, sizeof(search));
        for (int i = 1; i <= n; ++i) {
            search[i] = 0;
            for (int j = i - 1; j >= 1; --j) {
                if (prices[j - 1] < prices[i - 1]) {
                    search[i] = prices[i - 1] - prices[j - 1] + search[i];
                    maxp = max(maxp, search[i]);
                    break;
                }
            }
        }
        return search[n];
    }

    /**
     * Problem 814
     * We are given the head node root of a binary tree, where additionally every node's value is either a 0 or a 1.
     * Return the same tree where every subtree (of the given tree) not containing a 1 has been removed.
     */
    TreeNode* pruneTree(TreeNode* root) {
        if (root->left != nullptr) {
            root->left = pruneTree(root->left);
        }
        if (root->right != nullptr) {
            root->right = pruneTree(root->right);
        }
        if (root->left == nullptr && root->right == nullptr) {
            if (root->val == 0) {
                root = nullptr;
            }
        }
        return root;
    }
};
