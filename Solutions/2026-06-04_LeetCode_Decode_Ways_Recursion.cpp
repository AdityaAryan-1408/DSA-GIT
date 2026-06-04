/*

Problem Name   : Decode Ways
Platform       : LeetCode
Topic          : String, Dynamic Programming
Problem Link   : https://leetcode.com/problems/decode-ways/submissions/2022078224/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-04
Approach       : Recursion
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    int n;
    int helper(int i, string& s) {
        if (i == n) {
            return 1;
        }

        if (s[i] == '0')
            return 0;

        int onlyI = helper(i + 1, s);

        int iplus1 = 0;
        if (i + 1 < n) {
            if (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6') {
                iplus1 = helper(i + 2, s);
            }
        }
        return onlyI + iplus1;
    }
    int numDecodings(string s) {
        n = s.size();
        return helper(0, s);
    }
};
