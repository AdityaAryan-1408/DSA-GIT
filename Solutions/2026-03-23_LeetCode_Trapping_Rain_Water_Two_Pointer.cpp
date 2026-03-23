/*

Problem Name   : Trapping Rain Water
Platform       : LeetCode
Topic          : Array, Two Pointers, Dynamic Programming, Stack, Monotonic Stack
Problem Link   : https://leetcode.com/problems/trapping-rain-water/submissions/1956605252/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-03-23
Approach       : Two Pointer
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    int trap(vector<int>& height) {
        int lMax = 0, rMax = 0, total = 0;
    int n = height.size();
    int l = 0, r = n - 1;
    while (l < r) {
        if (height[l] <= height[r]) {
            if (lMax > height[l])
                total += lMax - height[l];
            else
                lMax = height[l];

            l++;
        } else {
            if (rMax > height[r])
                total += rMax - height[r];
            else
                rMax = height[r];

            r--;
        }
    }
    return total;
    }
};
