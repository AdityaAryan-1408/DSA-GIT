/*

Problem Name   : Kth Largest Element in an Array
Platform       : LeetCode
Topic          : Array, Divide and Conquer, Sorting, Heap (Priority Queue), Quickselect
Problem Link   : https://leetcode.com/problems/kth-largest-element-in-an-array/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-27
Approach       : Optimal
Time           : O(N log K)
Space          : O(K)

*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};
