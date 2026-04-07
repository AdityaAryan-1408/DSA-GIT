/*

Problem Name   : Non-overlapping Intervals
Platform       : LeetCode
Topic          : Array, Dynamic Programming, Greedy, Sorting, Intervals
Problem Link   : https://leetcode.com/problems/non-overlapping-intervals/submissions/1971480882/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-07
Approach       : Optimal
Time           : O(NlogN)
Space          : O(1)

*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();

        int cnt = 0;
        int i = 1;
        vector<int> last = intervals[0];
        while (i < n) {
            int currEnd = intervals[i][1];
            int currStart = intervals[i][0];

            int lastEnd = last[1];

            if (currStart >= lastEnd) {
                last = intervals[i];
            } else if (currEnd >= lastEnd) {
                cnt++;
            } else if (currEnd < lastEnd) {
                last = intervals[i];
                cnt++;
            }
            i++;
        }
        return cnt;
    }
};
