/*

Problem Name   : Max Sum Subarray of size K
Platform       : GeeksForGeeks
Topic          : Array, Sliding Window
Problem Link   :
https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1 Type :
POTD Difficulty     : Easy Date Solved    : 2026-01-05

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        int i = 0, j = 0;
        int sum = 0;
        int maxSum = -1;
        while (j < n) {
            sum += arr[j];
            int len = j - i + 1;
            if (len >= k) {
                if (len == k + 1) {
                    sum -= arr[i];
                    i++;
                }
                maxSum = max(sum, maxSum);
            }
            j++;
        }
        return maxSum;
    }
};

int main() {
    Solution s;

    return 0;
}