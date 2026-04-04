/*

Problem Name   : Task Scheduler
Platform       : LeetCode
Topic          : Array, Hash Table, Greedy, Sorting, Heap (Priority Queue), Counting
Problem Link   : https://leetcode.com/problems/task-scheduler/submissions/1968764380/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-04
Approach       : Max Heap

*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26, 0);
        for (char& c : tasks)
            mp[c - 'A']++;

        int time = 0;
        priority_queue<int> pq;

        for (int i = 0; i < 26; i++) {
            if (mp[i] > 0)
                pq.push(mp[i]);
        }

        while (!pq.empty()) {
            vector<int> temp;
            for (int i = 1; i <= n + 1; i++) {
                if (!pq.empty()) {
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for(int &f : temp){
                if(f > 0) pq.push(f);
            }

            if(pq.empty()){
                time += temp.size();
            }else{
                time += n + 1;
            }
        }
        return time;
    }
};

// TC = O(N)
// SC = O(1)
