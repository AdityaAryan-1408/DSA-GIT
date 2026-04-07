/*

Problem Name   : Merge Intervals
Platform       : LeetCode
Topic          : Array, Sorting
Problem Link   : https://leetcode.com/problems/merge-intervals/submissions/1971401899/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-07
Time           : O(NlogN)
Space          : O(1)

*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        vector<int> currentInterval = intervals[0];

        int n = intervals.size();
        for (int i = 1; i < n; i++) {
            if (currentInterval[1] >= intervals[i][0]) {
                currentInterval[0] = min(currentInterval[0], intervals[i][0]);
                currentInterval[1] = max(currentInterval[1], intervals[i][1]);
            } else if (currentInterval[1] < intervals[i][0]) {
                res.push_back(currentInterval);
                currentInterval = intervals[i];
            }
        }
        res.push_back(currentInterval);
        return res;
    }
};

// TC = O(NlogN)
// SC = O(N)
