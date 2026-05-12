/*

Problem Name   : Letter Combinations of a Phone Number
Platform       : LeetCode
Topic          : Hash Table, String, Backtracking
Problem Link   : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-12
Time           : O(4^N)
Space          : O(n * 4^n)

*/

class Solution {
public:
    void helper(string& digits, int i, string& current,
                map<char, vector<char>>& mp, vector<string>& res) {
        if (i == digits.size()) {
            res.push_back(current);
            return;
        }

        vector<char> curr = mp[digits[i]];
        for (int j = 0; j < curr.size(); j++) {
            current.push_back(curr[j]);
            helper(digits, i + 1, current, mp, res);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return {};

        map<char, vector<char>> mp;
        mp['2'] = {'a', 'b', 'c'};
        mp['3'] = {'d', 'e', 'f'};
        mp['4'] = {'g', 'h', 'i'};
        mp['5'] = {'j', 'k', 'l'};
        mp['6'] = {'m', 'n', 'o'};
        mp['7'] = {'p', 'q', 'r', 's'};
        mp['8'] = {'t', 'u', 'v'};
        mp['9'] = {'w', 'x', 'y', 'z'};

        string current = "";
        int i = 0;
        vector<string> res;
        helper(digits, i, current, mp, res);
        return res;
    }
};
