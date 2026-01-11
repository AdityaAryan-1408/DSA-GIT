/*

Problem Name   : Maximal Rectangle
Platform       : LeetCode
Topic          : DP
Problem Link   : https://leetcode.com/problems/maximal-rectangle/description/?envType=daily-question&envId=2026-01-11
Type           : POTD
Difficulty     : Hard
Date Solved    : 2026-01-11

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int largestRectangleArea(vector<int>& heights)  // From leetcode 84
    {
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<int> heights(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }
            int area = largestRectangleArea(heights);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};

int main() {
    Solution s;

    return 0;
}