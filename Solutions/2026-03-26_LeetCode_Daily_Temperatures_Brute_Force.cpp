/*

Problem Name   : Daily Temperatures
Platform       : LeetCode
Topic          : Array, Stack, Monotonic Stack
Problem Link   : https://leetcode.com/problems/daily-temperatures/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-26
Approach       : Brute Force
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (temp[j] > temp[i]) {
                    res[i] = (j - i);
                    break;
                }else{
                    res[i] = 0;
                }
            }
        }
        return res;
    }
};

// TC = O(N^2)
// SC = (1)
