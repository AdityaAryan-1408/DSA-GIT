/*

Problem Name   : Last Stone Weight
Platform       : LeetCode
Topic          : Array, Heap (Priority Queue)
Problem Link   : https://leetcode.com/problems/last-stone-weight/submissions/1967183982/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-04-02
Approach       : Heap
Time           : O(N + W)
Space          : O(W)

*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while (pq.size() != 1) {
            int f = pq.top();
            pq.pop();
            int s = pq.top();
            pq.pop();
            if (f != s) {
                pq.push(abs(f - s));
            } else {
                pq.push(0);
            }
        }
        return pq.top();
    }
};
