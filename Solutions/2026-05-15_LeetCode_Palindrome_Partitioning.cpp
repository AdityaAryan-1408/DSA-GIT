/*

Problem Name   : Palindrome Partitioning
Platform       : LeetCode
Topic          : String, Dynamic Programming, Backtracking
Problem Link   : https://leetcode.com/problems/palindrome-partitioning/submissions/2003706418/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-15
Time           : O(n^2 * 2^n)
Space          : O(n * 2^n)​

*/

class Solution {
public:
    vector<vector<string>> res;
    int n;
    bool isPalindrome(string& s, int i, int j) {
        int n = s.size();
        while (i <= j) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }

    void helper(int i, string& s, vector<string>& path) {
        if (i >= n) {
            res.push_back(path);
            return;
        }

        for (int j = i; j < n; j++) {
            if (isPalindrome(s, i, j)) {
                string temp = s.substr(i, j - i + 1);
                path.push_back(temp);
                helper(j + 1, s, path);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string& s) {
        n = s.size();
        vector<string> path;
        helper(0, s, path);
        return res;
    }
};
