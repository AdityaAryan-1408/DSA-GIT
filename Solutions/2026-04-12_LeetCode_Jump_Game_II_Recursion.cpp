/*

Problem Name   : Jump Game II
Platform       : LeetCode
Topic          : Array, Dynamic Programming, Greedy
Problem Link   : https://leetcode.com/problems/jump-game-ii/submissions/1976080433/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-12
Approach       : Recursion
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    int n;
    int helper(int ind, int jumps, vector<int>& nums) {
        if (ind >= n - 1) {
            return jumps;
        }

        int mini = INT_MAX;
        for (int i = 1; i <= nums[ind]; i++) {
            mini = min(mini, helper(ind + i, jumps + 1, nums));
        }
        return mini;
    }
    int jump(vector<int>& nums) {
        n = nums.size();
        return helper(0, 0, nums);
    }
};
