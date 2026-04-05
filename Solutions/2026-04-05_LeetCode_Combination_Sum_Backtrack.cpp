/*

Problem Name   : Combination Sum
Platform       : LeetCode
Topic          : Array, Backtracking
Problem Link   : https://leetcode.com/problems/combination-sum/submissions/1969877577/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-05
Approach       : Backtrack
Time           : O(2^t/m​)
Space          : O(t/m​)

*/

class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, int target, vector<int>& cur, int i) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        if (target < 0 || i >= nums.size()) {
            return;
        }

        cur.push_back(nums[i]);
        backtrack(nums, target - nums[i], cur, i);
        cur.pop_back();
        backtrack(nums, target, cur, i + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        backtrack(nums, target, cur, 0);
        return res;
    }
};
