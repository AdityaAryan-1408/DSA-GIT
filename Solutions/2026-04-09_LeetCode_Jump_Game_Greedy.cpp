/*

Problem Name   : Jump Game
Platform       : LeetCode
Topic          : Array, Dynamic Programming, Greedy
Problem Link   : https://leetcode.com/problems/jump-game/submissions/1973688625/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-09
Approach       : Greedy
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;

        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= goal) {
                goal = i;
            }
        }
        return goal == 0;
    }
};
