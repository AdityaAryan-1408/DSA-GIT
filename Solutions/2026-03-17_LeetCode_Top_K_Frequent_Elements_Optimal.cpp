/*

Problem Name   : Top K Frequent Elements
Platform       : LeetCode
Topic          : Array, Hash Table, Divide and Conquer, Sorting, Priority Queue, Bucket Sort, Counting, Quickselect
Problem Link   : https://leetcode.com/problems/top-k-frequent-elements/submissions/1951275031/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-17
Approach       : Optimal
Time           : O(N)
Space          : O(N)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums)
            freq[num]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>>pq;

        for (auto& p : freq) {
            pq.push({p.second, p.first});
            if (pq.size() > k)
                pq.pop();
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
