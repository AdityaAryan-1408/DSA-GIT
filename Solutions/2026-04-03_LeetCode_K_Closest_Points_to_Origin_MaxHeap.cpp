/*

Problem Name   : K Closest Points to Origin
Platform       : LeetCode
Topic          : Array, Math, Divide and Conquer, Geometry, Sorting, Heap (Priority Queue), Quickselect
Problem Link   : https://leetcode.com/problems/k-closest-points-to-origin/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-03
Approach       : MaxHeap
Time           : O(NlogN)
Space          : O(1)

*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        for (auto& point : points) {
            int dist = point[0] * point[0] + point[1] * point[1];
            pq.push({dist, point});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};

// TC = O(NlogK)
// SC = O(K)
