/*

Problem Name   : Find Median from Data Stream
Platform       : LeetCode
Topic          : Two Pointers, Design, Sorting, Heap (Priority Queue), Data Stream
Problem Link   : https://leetcode.com/problems/find-median-from-data-stream/submissions/1968964330/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-04-04
Time           : O(log N)
Space          : O(N)

*/

class MedianFinder {
   public:
    priority_queue<int> lMaxHeap;
    priority_queue<int, vector<int>, greater<int>> rMinHeap;

    MedianFinder() {}

    void addNum(int num) {
        if (lMaxHeap.empty() || num < lMaxHeap.top()) {
            lMaxHeap.push(num);
        } else {
            rMinHeap.push(num);
        }

        if (lMaxHeap.size() > rMinHeap.size() + 1) {
            rMinHeap.push(lMaxHeap.top());
            lMaxHeap.pop();
        } else if (rMinHeap.size() > lMaxHeap.size()) {
            lMaxHeap.push(rMinHeap.top());
            rMinHeap.pop();
        }
    }

    double findMedian() {
        if (lMaxHeap.size() > rMinHeap.size()) {
            return lMaxHeap.top();
        } else {
            return (lMaxHeap.top() + rMinHeap.top()) / 2.0;
        }
    }
};
