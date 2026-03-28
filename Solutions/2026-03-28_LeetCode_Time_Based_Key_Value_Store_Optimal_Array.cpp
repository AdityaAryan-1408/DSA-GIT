/*

Problem Name   : Time Based Key-Value Store
Platform       : LeetCode
Topic          : Hash Table, String, Binary Search, Design
Problem Link   : https://leetcode.com/problems/time-based-key-value-store/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-28
Approach       : Optimal - Array

*/

class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> keyStore;
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        keyStore[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        auto& values = keyStore[key];
        int left = 0, right = values.size() - 1;
        string result = "";
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (values[mid].first <= timestamp) {
                result = values[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};

// TC = O(1) for Set, O(log N) for Get
// SC = O(N * M)
