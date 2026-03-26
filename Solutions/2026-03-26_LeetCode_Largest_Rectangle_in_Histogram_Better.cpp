/*

Problem Name   : Largest Rectangle in Histogram
Platform       : LeetCode
Topic          : Array, Stack, Monotonic Stack
Problem Link   : https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/1960202091/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-03-26
Approach       : Better
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, heights[element] * (nse - pse - 1));
            }
            st.push(i);
        }
        while (!st.empty()) {
            int nse = n;
            int element = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, heights[element] * (nse - pse - 1));
        }
        return maxArea;
    }
};
