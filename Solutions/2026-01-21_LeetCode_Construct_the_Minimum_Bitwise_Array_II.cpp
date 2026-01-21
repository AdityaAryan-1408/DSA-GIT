/*

Problem Name   : Construct the Minimum Bitwise Array II
Platform       : LeetCode
Topic          : Bit Manipulation
Problem Link   : https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/description/?envType=daily-question&envId=2026-01-21
Type           : POTD
Difficulty     : Medium
Date Solved    : 2026-01-21

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for (int& x : nums) {
            int res = -1;
            int d = 1;
            while ((x & d) != 0) {
                res = x - d;
                d <<= 1;
            }
            x = res;
        }
        return nums;
    }
};

int main() {
    Solution s;

    return 0;
}