/*

Problem Name   : Maximum Matrix Sum
Platform       : LeetCode
Topic          : Array, Greedy
Problem Link   :
https://leetcode.com/problems/maximum-matrix-sum/description/?envType=daily-question&envId=2026-01-05
Type           : POTD
Difficulty     : Medium
Date Solved    : 2026-01-05

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int minAbsVal = INT_MAX;
        int negativeCount = 0;

        for (auto& row : matrix) {
            for (int val : row) {
                totalSum += abs(val);
                if (val < 0) {
                    negativeCount++;
                }
                minAbsVal = min(minAbsVal, abs(val));
            }
        }

        if (negativeCount % 2 != 0) {
            totalSum -= 2 * minAbsVal;
        }

        return totalSum;
    }
};

int main() {
    Solution s;

    return 0;
}