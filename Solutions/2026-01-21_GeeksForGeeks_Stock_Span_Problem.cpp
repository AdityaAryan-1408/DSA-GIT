/*

Problem Name   : Stock Span Problem
Platform       : GeeksForGeeks
Topic          : Stack
Problem Link   : https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
Type           : POTD
Difficulty     : Medium
Date Solved    : 2026-01-21

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> span(n);
        stack<int> st;  // stores indices

        for (int i = 0; i < n; i++) {
            // Pop elements smaller or equal to current
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            // If stack empty, span is full length
            span[i] = st.empty() ? (i + 1) : (i - st.top());

            // Push current index
            st.push(i);
        }
        return span;
    }
};

int main() {
    Solution s;

    return 0;
}