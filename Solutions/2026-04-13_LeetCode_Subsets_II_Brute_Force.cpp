/*

Problem Name   : Subsets II
Platform       : LeetCode
Topic          : Array, Backtracking, Bit Manipulation
Problem Link   : https://leetcode.com/problems/subsets-ii/submissions/1977359764/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-13
Approach       : Brute Force
Time           : O(N∗2N)
Space          : O(N)

*/

class Solution {
public:
    set<vector<int>>res;
    void helper(vector<int>&nums, int i, vector<int>subset){
        if(i == nums.size()){
            res.insert(subset);
            return;
        }

        subset.push_back(nums[i]);
        helper(nums, i + 1, subset);
        subset.pop_back();
        helper(nums, i + 1, subset);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        helper(nums, 0, {});
        return vector<vector<int>>(res.begin(), res.end());
    }
};
