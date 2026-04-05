/*

Problem Name   : Subsets
Platform       : LeetCode
Topic          : Array, Backtracking, Bit Manipulation
Problem Link   : https://leetcode.com/problems/subsets/submissions/1969428206/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-05
Approach       : Iteration
Time           : O(N * 2^N)
Space          : O(N)

*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};

        for (int num : nums) {
            int size = res.size();
            for (int i = 0; i < size; i++) {
                vector<int> subset = res[i];
                subset.push_back(num);
                res.push_back(subset);
            }
        }
        return res;
    }
};
