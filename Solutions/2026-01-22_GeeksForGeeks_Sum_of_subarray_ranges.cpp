/*

Problem Name   : Sum of subarray ranges
Platform       : GeeksForGeeks
Topic          : Array, Stack
Problem Link   : https://www.geeksforgeeks.org/problems/sum-of-subarray-ranges/1
Type           : POTD
Difficulty     : Medium
Date Solved    : 2026-01-22

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> ple(n), nle(n);
        stack<int> st;

        // Previous Less Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            ple[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Less Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            nle[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += 1LL * arr[i] * (i - ple[i]) * (nle[i] - i);
        }
        return sum;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> pge(n), nge(n);
        stack<int> st;

        // Previous Greater Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Greater Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += 1LL * arr[i] * (i - pge[i]) * (nge[i] - i);
        }
        return sum;
    }

    long long subarrayRanges(vector<int>& arr) {
        return sumSubarrayMaxs(arr) - sumSubarrayMins(arr);
    }
};

int main() {
    Solution s;

    return 0;
}