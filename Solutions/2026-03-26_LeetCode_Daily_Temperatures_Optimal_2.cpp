/*

Problem Name   : Daily Temperatures
Platform       : LeetCode
Topic          : Array, Stack, Monotonic Stack
Problem Link   : https://leetcode.com/problems/daily-temperatures/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-26
Approach       : Optimal 2
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<int> st;
        vector<int>res(n);
        for(int i = n -1; i>=0; i--){
            while(!st.empty() && temp[i] >= temp[st.top()]){
                st.pop();
            } 
            if(st.empty()) res[i] = 0;
            else{
                res[i] = st.top() - i;
            }
            st.push(i);
        }
        return res;
    }
};
