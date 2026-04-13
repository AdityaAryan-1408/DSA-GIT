/*

Problem Name   : Permutations
Platform       : LeetCode
Topic          : Array, Backtracking
Problem Link   : https://leetcode.com/problems/permutations/submissions/1977165215/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-13
Approach       : Backtracking Swap
Time           : O(N!)
Space          : O(N)

*/

class Solution {
public:
    vector<vector<int>>res;
    int n;
    void solve(int ind, vector<int>& nums){
        if(ind == n){
            res.push_back(nums);
            return;
        }
        for(int i = ind; i< n; i++){
            swap(nums[i], nums[ind]);
            solve(ind + 1, nums);
            swap(nums[i], nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        solve(0, nums);
        return res;
    }
};
