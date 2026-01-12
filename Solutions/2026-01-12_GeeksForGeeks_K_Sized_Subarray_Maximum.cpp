/*

Problem Name   : K Sized Subarray Maximum
Platform       : GeeksForGeeks
Topic          : Array, Sliding Window
Problem Link   : https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
Type           : POTD
Difficulty     : Medium
Date Solved    : 2026-01-12

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans;
        deque<int> dq;

        for (int j = 0; j < n; j++) {
            while (!dq.empty() && arr[dq.back()] <= arr[j]) dq.pop_back();

            dq.push_back(j);

            if (dq.front() <= j - k) dq.pop_front();

            if (j >= k - 1) ans.push_back(arr[dq.front()]);
        }

        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}