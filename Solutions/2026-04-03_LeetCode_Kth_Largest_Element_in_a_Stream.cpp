/*

Problem Name   : Kth Largest Element in a Stream
Platform       : LeetCode
Topic          : Tree, Design, Binary Search Tree, Heap (Priority Queue), Binary Tree, Data Stream
Problem Link   : https://leetcode.com/problems/kth-largest-element-in-a-stream/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-04-03
Time           : O(MlogK)
Space          : O(K)

*/

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > k)
            pq.pop();
        return pq.top();
    }
};
