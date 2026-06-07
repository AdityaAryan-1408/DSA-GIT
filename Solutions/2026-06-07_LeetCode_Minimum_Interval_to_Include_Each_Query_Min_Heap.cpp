/*

Problem Name   : Minimum Interval to Include Each Query
Platform       : LeetCode
Topic          : Array, Binary Search, Sweep Line, Sorting, Heap (Priority Queue)
Problem Link   : https://leetcode.com/problems/minimum-interval-to-include-each-query/submissions/2025250519/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-06-07
Approach       : Min Heap
Time           : O(nlogn+mlogm)
Space          : O(n+m)O(n+m)

*/

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // Sort intervals based on the start value
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[0] < b[0];
        });

        vector<int> sortedQueries = queries;
        sort(sortedQueries.begin(), sortedQueries.end());
        map<int, int> res;

        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] > b[1]);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> minHeap(cmp);

        int i = 0;
        for (int q : sortedQueries) {
            while (i < intervals.size() && intervals[i][0] <= q) {
                int l = intervals[i][0];
                int r = intervals[i][1];
                minHeap.push({r - l + 1, r});
                i++;
            }

            while (!minHeap.empty() && minHeap.top()[1] < q) {
                minHeap.pop();
            }

            res[q] = minHeap.empty() ? -1 : minHeap.top()[0];
        }

        vector<int> result(queries.size());
        for (int j = 0; j < queries.size(); j++) {
            result[j] = res[queries[j]];
        }
        return result;
    }
};
