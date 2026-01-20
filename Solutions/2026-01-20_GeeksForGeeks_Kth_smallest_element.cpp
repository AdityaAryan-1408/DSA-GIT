/*

Problem Name   : Kth smallest element
Platform       : GeeksForGeeks
Topic          : Priority Queue
Problem Link   : https://www.geeksforgeeks.org/problems/kth-smallest-element5545-1587115620--102500/1?page=1&difficulty=Medium&status=unsolved&sortBy=accuracy
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-01-20

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int kthSmallest(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int x : arr) pq.push(x);

        while (!pq.empty() && k != 1) {
            pq.pop();
            k--;
        }
        return pq.top();
    }
    int kthSmallestOptimal(vector<int>& arr, int k) {
        priority_queue<int> pq;
        for (int x : arr) {
            pq.push(x);
            if (pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};

int main() {
    Solution s;

    return 0;
}