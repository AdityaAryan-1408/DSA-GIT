/*

Problem Name   : Permutations
Platform       : LeetCode
Topic          : Array, Backtracking
Problem Link   : https://leetcode.com/problems/permutations/submissions/1977165215/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-13
Approach       : STL
Time           : O(N!)
Space          : O(N)

*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());
        vector<int>check = nums;
        do{
            next_permutation(nums.begin(), nums.end());
            res.push_back(nums);
        }while(check != nums);

        return res;
    }
};
