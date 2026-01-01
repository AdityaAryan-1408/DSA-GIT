/*

Problem Name   : Plus One
Platform       : LeetCode
Topic          : Array
Problem Link   : https://leetcode.com/problems/plus-one/?envType=daily-question&envId=2026-01-01
Type           : POTD
Difficulty     : Easy
Date Solved    : 2026-01-01

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();
        reverse(digits.begin(), digits.end());
        int carry = 0;
        for (int i = 0; i < n; i++)
        {
            int num = digits[i];
            if (i == 0)
                num = num + 1;
            else
            {
                num = num + carry;
            }
            if (num == 10)
            {
                carry = 1;
                digits[i] = 0;
            }
            else
            {
                digits[i] = num;
                carry = 0;
            }
        }
        if (carry == 1)
        {
            digits.push_back(1);
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};

int main()
{
    Solution s;

    return 0;
}