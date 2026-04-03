/*

Problem Name   : K Closest Points to Origin
Platform       : LeetCode
Topic          : Array, Math, Divide and Conquer, Geometry, Sorting, Heap (Priority Queue), Quickselect
Problem Link   : https://leetcode.com/problems/k-closest-points-to-origin/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-03
Approach       : Sorting
Time           : O(NlogN)
Space          : O(1)

*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [](const auto &a, const auto &b){
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        });

        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};

// TC = O(NlogN)
// SC = O(1)
