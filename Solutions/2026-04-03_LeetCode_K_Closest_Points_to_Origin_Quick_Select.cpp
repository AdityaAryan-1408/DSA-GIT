/*

Problem Name   : K Closest Points to Origin
Platform       : LeetCode
Topic          : Array, Math, Divide and Conquer, Geometry, Sorting, Heap (Priority Queue), Quickselect
Problem Link   : https://leetcode.com/problems/k-closest-points-to-origin/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-03
Approach       : Quick Select
Time           : O(NlogN)
Space          : O(1)

*/

class Solution {
public:
    int euclidean(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }
    int partition(vector<vector<int>>& points, int l, int r) {
        int pivotInd = r;
        int pivotDist = euclidean(points[pivotInd]);
        int i = l;
        for (int j = l; j < r; j++) {
            if (euclidean(points[j]) <= pivotDist) {
                swap(points[i], points[j]);
                i++;
            }
        }
        swap(points[i], points[r]);
        return i;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int L = 0, R = points.size() - 1;
        int pivot = points.size();

        while (pivot != k) {
            pivot = partition(points, L, R);
            if (pivot < k) {
                L = pivot + 1;
            } else {
                R = pivot - 1;
            }
        }
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};

// TC = O(N) in Average case, O(N^2) in worst case
// SC = O(1)
