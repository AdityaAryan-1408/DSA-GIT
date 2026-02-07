/*

Problem Name   : Max sum in the configuration
Platform       : GeeksForGeeks
Topic          : Array
Problem Link   : https://www.geeksforgeeks.org/problems/max-sum-in-the-configuration/1
Type           : POTD
Difficulty     : Medium
Date Solved    : 2026-02-07

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxSum(vector<int>& arr) {
        // code here
        long long n = arr.size();
        long long totalSum = 0;
        long long currentRotationSum = 0;

        for (long long i = 0; i < n; i++) {
            totalSum += arr[i];
            currentRotationSum += i * arr[i];
        }

        long long maxVal = currentRotationSum;

        for (int i = 1; i < n; i++) {
            long long nextRotationSum =
                currentRotationSum + totalSum - n * (long long)arr[n - i];
            currentRotationSum = nextRotationSum;
            maxVal = max(maxVal, currentRotationSum);
        }

        return (int)maxVal;
    }
};

int main() {
    Solution s;

    return 0;
}