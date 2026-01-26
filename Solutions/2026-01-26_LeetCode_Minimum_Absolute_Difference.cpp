/*

Problem Name   : Minimum Absolute Difference
Platform       : LeetCode
Topic          : Array, Sorting
Problem Link   : https://leetcode.com/problems/minimum-absolute-difference/description/?envType=daily-question&envId=2026-01-26
Type           : POTD
Difficulty     : Easy
Date Solved    : 2026-01-26

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int minDiff = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            int diff = abs(arr[i] - arr[i + 1]);
            minDiff = min(minDiff, diff);
        }

        for (int i = 0; i < n - 1; i++) {
            if (abs(arr[i] - arr[i + 1]) == minDiff)
                res.push_back({arr[i], arr[i + 1]});
        }
        sort(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution s;

    return 0;
}