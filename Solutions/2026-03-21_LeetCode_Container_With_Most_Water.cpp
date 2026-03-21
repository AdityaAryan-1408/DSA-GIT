/*

Problem Name   : Container With Most Water
Platform       : LeetCode
Topic          : Array, Two Pointers, Greedy
Problem Link   : https://leetcode.com/problems/container-with-most-water/submissions/1955066604/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-21
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n - 1;
        int maxWater = 0;
        while (i <= j) {
            int h = min(height[i], height[j]);
            int w = j - i;
            maxWater = max(maxWater, h * w);
            if(height[i] <= height[j])
                i++;
            else
                j--;
        }
        return maxWater;
    }
};
