/*

Problem Name   : Generate Parentheses
Platform       : LeetCode
Topic          : String, Dynamic Programming, Backtracking
Problem Link   : https://leetcode.com/problems/generate-parentheses/submissions/1979403085/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-15
Approach       : Backtracking
Time           : O(2^2N)
Space          : O(2N)

*/

class Solution {
public:
    vector<string> res;
    bool isValid(string& str) {
        int cnt = 0;
        for (char c : str) {
            if (c == '(') {
                cnt++;
            } else {
                cnt--;
            }
            if (cnt < 0)
                return false;
        }
        return cnt == 0;
    }
    void helper(string& curr, int n) {
        if (curr.size() == 2 * n) {
            if (isValid(curr)) {
                res.push_back(curr);
            }
            return;
        }
        curr.push_back('(');
        helper(curr, n);
        curr.pop_back();
        curr.push_back(')');
        helper(curr, n);
        curr.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";
        helper(curr, n);
        return res;
    }
};

// TC = O(2N * 2^2N)
// SC = O(2N)
