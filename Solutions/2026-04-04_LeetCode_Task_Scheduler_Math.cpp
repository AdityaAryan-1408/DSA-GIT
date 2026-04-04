/*

Problem Name   : Task Scheduler
Platform       : LeetCode
Topic          : Array, Hash Table, Greedy, Sorting, Heap (Priority Queue), Counting
Problem Link   : https://leetcode.com/problems/task-scheduler/submissions/1968764380/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-04
Approach       : Math

*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26, 0);
        for (char& c : tasks)
            mp[c - 'A']++;

        sort(mp.begin(), mp.end());
        int maxF = mp[25];
        int idle = (maxF - 1) * n;

        for (int i = 24; i >= 0; i--) {
            idle -= min(maxF - 1, mp[i]);
        }
        return max(0, idle) + tasks.size();
    }
};

// TC = O(N)
// SC = O(1)
