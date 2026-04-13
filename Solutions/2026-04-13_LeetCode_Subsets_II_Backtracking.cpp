/*

Problem Name   : Subsets II
Platform       : LeetCode
Topic          : Array, Backtracking, Bit Manipulation
Problem Link   : https://leetcode.com/problems/subsets-ii/submissions/1977359764/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-13
Approach       : Backtracking
Time           : O(N∗2N)
Space          : O(N)

*/

class Solution {
public:
    vector<vector<int>> res;
    void helper(int i, vector<int> subset, vector<int>& nums) {
        if (i == nums.size()) {
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        helper(i + 1, subset, nums);
        subset.pop_back();

        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
        helper(i + 1, subset, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        helper(0, {}, nums);
        return res;
    }
};
