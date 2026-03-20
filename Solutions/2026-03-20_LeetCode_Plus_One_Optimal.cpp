/*

Problem Name   : Plus One
Platform       : LeetCode
Topic          : Array, Math
Problem Link   : https://leetcode.com/problems/plus-one/submissions/1953919079/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-03-20
Approach       : Optimal
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};
