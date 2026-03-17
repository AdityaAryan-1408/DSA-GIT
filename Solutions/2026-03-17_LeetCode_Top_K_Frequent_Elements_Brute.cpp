/*

Problem Name   : Top K Frequent Elements
Platform       : LeetCode
Topic          : Array, Hash Table, Divide and Conquer, Sorting, Priority Queue, Bucket Sort, Counting, Quickselect
Problem Link   : https://leetcode.com/problems/top-k-frequent-elements/submissions/1951275031/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-17
Approach       : Brute
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

        vector<pair<int, int>> temp;
        for (auto& entry : hm) {
            temp.push_back({entry.second, entry.first});
        }

        sort(temp.begin(), temp.end(), greater<pair<int, int>>());

        for (int i = 0; i < k; i++) {
            ans.push_back(temp[i].second);
        }

        return ans;
    }
};

// TC = O(NlogN)
// SC = O(N)
