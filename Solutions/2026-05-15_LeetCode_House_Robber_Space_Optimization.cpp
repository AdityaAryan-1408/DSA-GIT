/*

Problem Name   : House Robber
Platform       : LeetCode
Topic          : Array, Dynamic Programming
Problem Link   : https://leetcode.com/problems/house-robber/submissions/2003720947/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-15
Approach       : Space Optimization
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    int n;
    int helper(vector<int>& nums) {
        int prev = nums[0];
        int prev2 = 0, curr;
        int pick, notPick;
        for (int i = 1; i < n; i++) {
            pick = nums[i];
            if (i > 1)
                pick += prev2;

            notPick = prev;
           curr = max(pick, notPick);
           prev2 = prev;
           prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        return helper(nums);
    }
};
