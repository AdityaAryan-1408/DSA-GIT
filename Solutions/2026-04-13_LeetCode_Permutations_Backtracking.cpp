/*

Problem Name   : Permutations
Platform       : LeetCode
Topic          : Array, Backtracking
Problem Link   : https://leetcode.com/problems/permutations/submissions/1977165215/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-13
Approach       : Backtracking
Time           : O(N!)
Space          : O(N)

*/

class Solution {
public:
    vector<vector<int>> res;
    unordered_set<int> st;
    int n;
    void solve(vector<int>& temp, vector<int>& nums) {
        if (temp.size() == n) {
            res.push_back(temp);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (st.find(nums[i]) == st.end()) {
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                solve(temp, nums);
                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<int> temp;
        solve(temp, nums);
        return res;
    }
};
