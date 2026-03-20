/*

Problem Name   : Plus One
Platform       : LeetCode
Topic          : Array, Math
Problem Link   : https://leetcode.com/problems/plus-one/submissions/1953919079/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-03-20
Approach       : Alternative
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int carry = 1;
        for (int i = 0; i < digits.size(); i++) {
            int sum = digits[i] + carry;
            if (sum == 10) {
                digits[i] = 0;
                carry = 1;
            }else{
                digits[i] = sum;
                carry = 0;
            }
        }

        if (carry) {
            digits.push_back(1);
        }

        reverse(digits.begin(), digits.end());
        return digits;
    }
};

// TC = O(3N) ~ O(N)
// SC = O(N)
