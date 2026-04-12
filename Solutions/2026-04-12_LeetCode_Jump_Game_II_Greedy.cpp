/*

Problem Name   : Jump Game II
Platform       : LeetCode
Topic          : Array, Dynamic Programming, Greedy
Problem Link   : https://leetcode.com/problems/jump-game-ii/submissions/1976080433/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-12
Approach       : Greedy
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int l = 0, r = 0;
        while (r < n - 1) {
            int farthest = 0;
            for (int i = l; i <= r; i++) {
                farthest = max(farthest, i + nums[i]);
            }
            l = r + 1;
            r = farthest;
            jumps++;
        }
        return jumps;
    }
};
