/*

Problem Name   : Subsets
Platform       : LeetCode
Topic          : Array, Backtracking, Bit Manipulation
Problem Link   : https://leetcode.com/problems/subsets/submissions/1969428206/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-05
Approach       : Backtracking
Time           : O(N * 2^N)
Space          : O(N)

*/

class Solution {
public:
    set<vector<int>> st;
    int n;
    void helper(int i, vector<int>& nums, vector<int>& temp) {
        if (i == n) {
            st.insert(temp);
            return;
        }
        temp.push_back(nums[i]);
        helper(i + 1, nums,temp);
        temp.pop_back();
        helper(i + 1, nums,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> temp;
        helper(0, nums, temp);
        vector<vector<int>> res(st.begin(), st.end());
        return res;
    }
};
