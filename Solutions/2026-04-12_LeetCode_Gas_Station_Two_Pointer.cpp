/*

Problem Name   : Gas Station
Platform       : LeetCode
Topic          : Array, Greedy
Problem Link   : https://leetcode.com/problems/gas-station/submissions/1976147599/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-12
Approach       : Two Pointer
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start = n - 1, end = 0;
        int tank = gas[start] - cost[start];
        while (start > end) {
            if (tank < 0) {
                start--;
                tank += gas[start] - cost[start];
            } else {
                tank += gas[end] - cost[end];
                end++;
            }
        }
        return tank >= 0 ? start : -1;
    }
};
