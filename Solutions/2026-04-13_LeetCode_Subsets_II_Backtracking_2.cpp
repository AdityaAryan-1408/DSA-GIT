/*

Problem Name   : Subsets II
Platform       : LeetCode
Topic          : Array, Backtracking, Bit Manipulation
Problem Link   : https://leetcode.com/problems/subsets-ii/submissions/1977359764/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-13
Approach       : Backtracking 2
Time           : O(N∗2N)
Space          : O(N)

*/

class Solution {
public:
    vector<vector<int>> res;
    void helper(int i, vector<int> subset, vector<int>& nums) {
        res.push_back(subset);
        for(int j = i; j< nums.size(); j++){
            if(j > i && nums[j] == nums[j - 1]){
                continue;
            }

            subset.push_back(nums[j]);
            helper(j + 1, subset, nums);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        helper(0, {}, nums);
        return res;
    }
};
