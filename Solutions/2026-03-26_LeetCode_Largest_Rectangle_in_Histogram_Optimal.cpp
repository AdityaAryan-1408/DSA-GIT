/*

Problem Name   : Largest Rectangle in Histogram
Platform       : LeetCode
Topic          : Array, Stack, Monotonic Stack
Problem Link   : https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/1960202091/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-03-26
Approach       : Optimal
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        for (int i = 0; i <= heights.size(); i++) {
            int currHeight = (i == n) ? 0 : heights[i];
            while (!st.empty() && currHeight < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, width * height);
            }
            st.push(i);
        }
        return maxArea;
    }
};
