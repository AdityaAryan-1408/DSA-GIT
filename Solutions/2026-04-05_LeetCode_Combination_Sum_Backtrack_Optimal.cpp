/*

Problem Name   : Combination Sum
Platform       : LeetCode
Topic          : Array, Backtracking
Problem Link   : https://leetcode.com/problems/combination-sum/submissions/1969877577/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-05
Approach       : Backtrack Optimal
Time           : O(2^t/m​)
Space          : O(t/m​)

*/

class Solution {
public:
    vector<vector<int>> res;
    void dfs(int i, vector<int> cur, int total, vector<int>& nums, int target) {
        if (total == target) {
            res.push_back(cur);
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            if (total + nums[j] > target) {
                return;
            }
            cur.push_back(nums[j]);
            dfs(j, cur, total + nums[j], nums, target);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        dfs(0, {}, 0, nums, target);
        return res;
    }
};
