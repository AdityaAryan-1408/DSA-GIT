/*

Problem Name   : Partition Equal Subset Sum
Platform       : LeetCode
Topic          : Array, Dynamic Programming
Problem Link   : https://leetcode.com/problems/partition-equal-subset-sum/submissions/2023995080/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-06
Approach       : Space Optimization

*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 == 1)
            return false;
        int target = total / 2;

        vector<int>prev(target + 1), curr(target + 1);
        prev[0] = true;
        curr[0] = true;
        if (nums[0] <= target) {
            prev[nums[0]] = true;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                bool notTake = prev[j];
                bool take = false;
                if (j >= nums[i]) {
                    take = prev[j - nums[i]];
                }
                curr[j] = take || notTake;
            }
            prev = curr;
        }
        return prev[target];
    }
};
