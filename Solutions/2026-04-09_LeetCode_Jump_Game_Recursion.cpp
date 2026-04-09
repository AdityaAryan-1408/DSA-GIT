/*

Problem Name   : Jump Game
Platform       : LeetCode
Topic          : Array, Dynamic Programming, Greedy
Problem Link   : https://leetcode.com/problems/jump-game/submissions/1973688625/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-09
Approach       : Recursion
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    int helper(vector<int>& nums, int i) {
        if (i == nums.size() - 1) {
            return true;
        }
        int end = min((int)nums.size() - 1, i + nums[i]);
        for (int j = i + 1; j <= end; j++) {
            if(helper(nums, j)){
                return true;
            }
        }
        return false;
    }
    bool canJump(vector<int>& nums) { return helper(nums, 0); }
};
