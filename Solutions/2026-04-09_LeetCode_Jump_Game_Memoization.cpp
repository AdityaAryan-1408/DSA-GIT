/*

Problem Name   : Jump Game
Platform       : LeetCode
Topic          : Array, Dynamic Programming, Greedy
Problem Link   : https://leetcode.com/problems/jump-game/submissions/1973688625/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-09
Approach       : Memoization
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    bool dfs(vector<int>& nums, int i, unordered_map<int, bool>& memo) {
        if (memo.count(i)) {
            return memo[i];
        }
        if (i == nums.size() - 1) {
            return true;
        }
        if (nums[i] == 0) {
            return false;
        }

        int end = min((int)nums.size(), i + nums[i] + 1);
        for (int j = i + 1; j < end; j++) {
            if (dfs(nums, j, memo)) {
                memo[i] = true;
                return true;
            }
        }
        memo[i] = false;
        return false;
    }
    bool canJump(vector<int>& nums) {
        unordered_map<int, bool> memo;
        return dfs(nums, 0, memo);
    }
};
