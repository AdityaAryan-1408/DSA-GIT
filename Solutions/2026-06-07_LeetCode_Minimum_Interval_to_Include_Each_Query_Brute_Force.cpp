/*

Problem Name   : Minimum Interval to Include Each Query
Platform       : LeetCode
Topic          : Array, Binary Search, Sweep Line, Sorting, Heap (Priority Queue)
Problem Link   : https://leetcode.com/problems/minimum-interval-to-include-each-query/submissions/2025250519/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-06-07
Approach       : Brute Force
Time           : O(nlogn+mlogm)
Space          : O(n+m)O(n+m)

*/

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> res;
        for (int q : queries) {
            int cur = -1;
            for (auto& interval : intervals) {
                int l = interval[0], r = interval[1];
                if (l <= q && q <= r) {
                    if (cur == -1 || (r - l + 1) < cur) {
                        cur = r - l + 1;
                    }
                }
            }
            res.push_back(cur);
        }
        return res;
    }
};
