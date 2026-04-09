/*

Problem Name   : Maximum Subarray
Platform       : LeetCode
Topic          : Array, Divide and Conquer, Dynamic Programming
Problem Link   : https://leetcode.com/problems/maximum-subarray/submissions/1973604744/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-09
Approach       : Kadane's Algorithm
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = INT_MIN;
        for (int num : nums) {
            sum += num;
            maxi = max(sum, maxi);
            if (sum < 0) {
                sum = 0;
            }
        }
        return maxi;
    }
};
