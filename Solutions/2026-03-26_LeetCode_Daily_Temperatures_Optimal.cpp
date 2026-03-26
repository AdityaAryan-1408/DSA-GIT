/*

Problem Name   : Daily Temperatures
Platform       : LeetCode
Topic          : Array, Stack, Monotonic Stack
Problem Link   : https://leetcode.com/problems/daily-temperatures/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-26
Approach       : Optimal
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<int> st;
        vector<int> res(n, 0);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temp[i] > temp[st.top()]) {
                int ind = st.top();
                st.pop();
                res[ind] = i - ind;
            }
            st.push(i);
        }
        return res;
    }
};
