/*

Problem Name   : Target Sum
Platform       : LeetCode
Topic          : Array, Dynamic Programming, Backtracking
Problem Link   : https://leetcode.com/problems/target-sum/submissions/2020063647/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-02
Approach       : Memoization with Map
Time           : O(N * S)
Space          : O(N * S)

*/

class Solution {
public:
    int helper(vector<int>& nums, int target, int i, int curr,
               unordered_map<string, int>& mp) {
        if (i == nums.size()) {
            if (curr == target)
                return 1;
            return 0;
        }

        string key = to_string(i) + "_" + to_string(curr);
        if (mp.count(key))
            return mp[key];

        int plus = helper(nums, target, i + 1, curr + nums[i], mp);
        int minus = helper(nums, target, i + 1, curr - nums[i], mp);
        return mp[key] = plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> mp;
        return helper(nums, target, 0, 0, mp);
    }
};
