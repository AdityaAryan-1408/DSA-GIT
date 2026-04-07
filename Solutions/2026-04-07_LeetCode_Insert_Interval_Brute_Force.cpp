/*

Problem Name   : Insert Interval
Platform       : LeetCode
Topic          : Array
Problem Link   : https://leetcode.com/problems/insert-interval/submissions/1971380727/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-07
Approach       : Brute Force
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        while(i < intervals.size()){
            if(intervals[i][1] < newInterval[0]){
                i++;
            }else if(intervals[i][0] > newInterval[1]){
                intervals.insert(intervals.begin() + i, newInterval);
                return intervals;
            }else{
                newInterval[0]= min(newInterval[0], intervals[i][0]);
                newInterval[1]= max(newInterval[1], intervals[i][1]);
                intervals.erase(intervals.begin() + i);
            }
        }

        intervals.push_back(newInterval);
        return intervals;
    }
}; 

// TC = O(N^2)
// SC = O(1)
