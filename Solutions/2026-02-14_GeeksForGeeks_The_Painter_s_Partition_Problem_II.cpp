/*

Problem Name   : The Painter's Partition Problem-II
Platform       : GeeksForGeeks
Topic          : Binary Search
Problem Link   : https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1
Type           : POTD
Difficulty     : Hard
Date Solved    : 2026-02-14

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool canPaint(vector<int>& arr, int k, long long maxTime) {
        long long currSum = 0;
        int painters = 1;

        for (int len : arr) {
            if (currSum + len <= maxTime) {
                currSum += len;
            } else {
                painters++;
                currSum = len;
                if (painters > k) return false;
            }
        }
        return true;
    }
    int minTime(vector<int>& arr, int k) {
        long long low = *max_element(arr.begin(), arr.end());
        long long high = accumulate(arr.begin(), arr.end(), 0LL);
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (canPaint(arr, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}