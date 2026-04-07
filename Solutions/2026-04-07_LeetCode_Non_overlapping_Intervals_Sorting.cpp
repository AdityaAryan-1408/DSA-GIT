/*

Problem Name   : Non-overlapping Intervals
Platform       : LeetCode
Topic          : Array, Dynamic Programming, Greedy, Sorting, Intervals
Problem Link   : https://leetcode.com/problems/non-overlapping-intervals/submissions/1971480882/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-07
Approach       : Sorting
Time           : O(NlogN)
Space          : O(1)

*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int cnt = 0;
        int i = 0, j = 1;
        while (j < intervals.size()) {
            vector<int> curr = intervals[i];
            vector<int> next = intervals[j];

            int cs = curr[0];
            int ce = curr[1];
            int ns = next[0];
            int ne = next[1];

            if (ce <= ns) {
                i = j;
                j++;
            } else if (ce <= ne) {
                j++;
                cnt++;
            }else if(ce > ne){
                i = j;
                j++;
                cnt++;
            }
        }
        return cnt;
    }
};
