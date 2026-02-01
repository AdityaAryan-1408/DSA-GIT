/*

Problem Name   : Divide an Array Into Subarrays With Minimum Cost I
Platform       : LeetCode
Topic          : Sorting
Problem Link   : https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/description/?envType=daily-question&envId=2026-02-01
Type           : POTD
Difficulty     : Easy
Date Solved    : 2026-02-01

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minimumCost(vector<int>& nums) {
        sort(nums.begin() + 1, nums.end());
        return nums[0] + nums[1] + nums[2];
    }
};

int main() {
    Solution s;

    return 0;
}