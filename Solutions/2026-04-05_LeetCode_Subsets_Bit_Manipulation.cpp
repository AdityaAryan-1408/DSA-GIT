/*

Problem Name   : Subsets
Platform       : LeetCode
Topic          : Array, Backtracking, Bit Manipulation
Problem Link   : https://leetcode.com/problems/subsets/submissions/1969428206/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-05
Approach       : Bit Manipulation
Time           : O(N * 2^N)
Space          : O(N)

*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int subs = 1 << n;
        vector<vector<int>> res;
        for (int i = 0; i < subs; i++) {
            vector<int> lst;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j))
                    lst.push_back(nums[j]);
            }
            res.push_back(lst);
        }
        return res;
    }
};
