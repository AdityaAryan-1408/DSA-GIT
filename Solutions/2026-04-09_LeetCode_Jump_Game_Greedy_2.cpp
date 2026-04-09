/*

Problem Name   : Jump Game
Platform       : LeetCode
Topic          : Array, Dynamic Programming, Greedy
Problem Link   : https://leetcode.com/problems/jump-game/submissions/1973688625/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-09
Approach       : Greedy 2
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxInd = 0;
        for (int i = 0; i < n; i++) {
            if (i > maxInd)
                return false;
            maxInd = max(maxInd, i + nums[i]);
        }

        return true;
    }
};
