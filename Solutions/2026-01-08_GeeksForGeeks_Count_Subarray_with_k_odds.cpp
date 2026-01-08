/*

Problem Name   : Count Subarray with k odds
Platform       : GeeksForGeeks
Topic          : Array, Sliding Window
Problem Link   : https://www.geeksforgeeks.org/problems/count-subarray-with-k-odds/1
Type           : POTD
Difficulty     : Medium
Date Solved    : 2026-01-08

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int atMost(vector<int>& arr, int k) {
        int left = 0, oddCount = 0, res = 0;

        for (int right = 0; right < arr.size(); right++) {
            if (arr[right] % 2 == 1) oddCount++;

            while (oddCount > k) {
                if (arr[left] % 2 == 1) oddCount--;
                left++;
            }

            res += (right - left + 1);
        }

        return res;
    }
    int countSubarrays(vector<int>& arr, int k) {
        return atMost(arr, k) - atMost(arr, k - 1);
    }
};

int main() {
    Solution s;

    return 0;
}