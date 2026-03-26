/*

Problem Name   : Largest Rectangle in Histogram
Platform       : LeetCode
Topic          : Array, Stack, Monotonic Stack
Problem Link   : https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/1960202091/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-03-26
Approach       : Brute Force
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    vector<int> findPSE(vector<int> arr) {
        int n = arr.size();
        vector<int> pse(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            if (st.empty()) {
                pse[i] = -1;
            } else
                pse[i] = st.top();

            st.push(i);
        }
        return pse;
    }
    vector<int> findNSE(vector<int> arr) {
        int n = arr.size();
        vector<int> nse(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            if (st.empty()) {
                nse[i] = n;
            } else
                nse[i] = st.top();

            st.push(i);
        }
        return nse;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> pse = findPSE(heights);
        vector<int> nse = findNSE(heights);
        int area = 0;
        for (int i = 0; i < heights.size(); i++) {
            int carea = heights[i] * (nse[i] - pse[i] - 1);
            area = max(area, carea);
        }
        return area;
    }
};

// TC = O(5N)
// SC = O(4N)
