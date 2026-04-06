/*

Problem Name   : Combination Sum II
Platform       : LeetCode
Topic          : Array, Backtracking
Problem Link   : https://leetcode.com/problems/combination-sum-ii/submissions/1970681685/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-06
Time           : O(N * 2^N)
Space          : O(N)

*/

class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<int>& curr, int ind,
               vector<vector<int>>& res) {
        if (target < 0)
            return;
        if (target == 0) {
            res.push_back(curr);
            return;
        }

        for (int i = ind; i < candidates.size(); i++) {
            if (i > ind && candidates[i] == candidates[i - 1]) {
                continue;
            }
            curr.push_back(candidates[i]);
            solve(candidates, target - candidates[i], curr, i + 1, res);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, curr, 0, res);
        return res;
    }
};
