/*

Problem Name   : Top K Frequent Elements
Platform       : LeetCode
Topic          : Array, Hash Table, Divide and Conquer, Sorting, Priority Queue, Bucket Sort, Counting, Quickselect
Problem Link   : https://leetcode.com/problems/top-k-frequent-elements/submissions/1951275031/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-17
Approach       : Better
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> hm;

        for (int num : nums) {
            hm[num]++;
        }

        priority_queue<pair<int, int>> pq;
        for (auto& entry : hm) {
            pq.push({entry.second, entry.first});
        }
        while (!pq.empty() && k > 0) {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return ans;
    }
};

// TC = O(N)
// SC = O(N)
