/*

Problem Name   : Next element with greater frequency
Platform       : GeeksForGeeks
Topic          : Hash, Stack
Problem Link   : https://www.geeksforgeeks.org/problems/next-element-with-greater-frequency--170637/1
Type           : POTD
Difficulty     : Medium
Date Solved    : 2026-01-18

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> ans(n, -1);
        unordered_map<int, int> freq;

        // Step 1: Count frequencies
        for (int x : arr) freq[x]++;

        // Step 2: Stack for NGFE
        stack<int> st;

        // Step 3: Traverse from right
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && freq[st.top()] <= freq[arr[i]]) st.pop();

            if (!st.empty()) ans[i] = st.top();

            st.push(arr[i]);
        }

        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}