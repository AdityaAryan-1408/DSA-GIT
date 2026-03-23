/*

Problem Name   : Trapping Rain Water
Platform       : LeetCode
Topic          : Array, Two Pointers, Dynamic Programming, Stack, Monotonic Stack
Problem Link   : https://leetcode.com/problems/trapping-rain-water/submissions/1956605252/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-03-23
Approach       : Prefix-Suffix Optimized
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lastMax = height[0];
        vector<int> suffixMax(n, -1);

        suffixMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suffixMax[i] = max(suffixMax[i + 1], height[i]);

        int total = 0;
        for (int i = 0; i < n; i++) {
            int leftMax = max(lastMax, height[i]);
            if(leftMax != lastMax){
                lastMax = leftMax;
            }
            int rightMax = suffixMax[i];
            if (height[i] < leftMax && height[i] < rightMax) {
                total += min(leftMax, rightMax) - height[i];
            }
        }
        return total;
    }
};

// Optimized by removing the prefix array by remebering the last greatest element.
// TC = O(2N) ~ O(N)
// SC = O(N) ~ O(N)
