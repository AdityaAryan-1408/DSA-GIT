/*

Problem Name   : Generate Parentheses
Platform       : LeetCode
Topic          : String, Dynamic Programming, Backtracking
Problem Link   : https://leetcode.com/problems/generate-parentheses/submissions/1979403085/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-15
Approach       : Optimal
Time           : O(2^2N)
Space          : O(2N)

*/

class Solution {
public:
    vector<string> res;
    void helper(string& curr, int n, int open, int close) {
        if (curr.size() == 2 * n) {
            res.push_back(curr);
            return;
        }
        if (open < n) {
            curr.push_back('(');
            helper(curr, n, open + 1, close);
            curr.pop_back();
        }
        if (close < open) {
            curr.push_back(')');
            helper(curr, n, open, close + 1);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";
        int open = 0, close = 0;
        helper(curr, n, open, close);
        return res;
    }
};
