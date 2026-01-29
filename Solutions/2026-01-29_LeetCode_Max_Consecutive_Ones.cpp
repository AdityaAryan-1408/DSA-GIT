/*

Problem Name   : Max Consecutive Ones
Platform       : LeetCode
Topic          : Array
Problem Link   : https://leetcode.com/problems/max-consecutive-ones/description/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-01-29

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int oneCount = 0;
        int maxOne = -1;
        for (int num : nums) {
            if (num == 1) {
                oneCount++;
            } else {
                maxOne = max(maxOne, oneCount);
                oneCount = 0;
            }
        }
        maxOne = max(maxOne, oneCount);
        return maxOne;
    }
};

int main() {
    Solution s;

    return 0;
}