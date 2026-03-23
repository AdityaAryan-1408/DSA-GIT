/*

Problem Name   : Trapping Rain Water
Platform       : LeetCode
Topic          : Array, Two Pointers, Dynamic Programming, Stack, Monotonic Stack
Problem Link   : https://leetcode.com/problems/trapping-rain-water/submissions/1956605252/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-03-23
Approach       : Stack
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st; // stores indices
        int water = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int bottom = st.top();
                st.pop();

                if (st.empty()) break;

                int left = st.top();
                int width = i - left - 1;
                int boundedHeight = min(height[i], height[left]) - height[bottom];

                water += width * boundedHeight;
            }
            st.push(i);
        }

        return water;
    }
};
