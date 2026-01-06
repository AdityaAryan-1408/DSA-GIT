/*

Problem Name   : Max Xor Subarray of size K
Platform       : GeeksForGeeks
Topic          : Array, Sliding Window
Problem Link   : https://www.geeksforgeeks.org/problems/max-xor-subarray-of-size-k/1
Type           : POTD
Difficulty     : Medium
Date Solved    : 2026-01-06

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int n = arr.size();
        int x = 0;
        int i = 0, j = 0;
        int maxor = 0;
        while (j < n) {
            x = x ^ arr[j];
            int len = j - i + 1;
            if (len >= k) {
                if (len == k + 1) {
                    x = x ^ arr[i];
                    i++;
                }
                maxor = max(maxor, x);
            }
            j++;
        }
        return maxor;
    }
};

int main() {
    Solution s;

    return 0;
}