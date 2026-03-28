/*

Problem Name   : Time Based Key-Value Store
Platform       : LeetCode
Topic          : Hash Table, String, Binary Search, Design
Problem Link   : https://leetcode.com/problems/time-based-key-value-store/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-28
Approach       : Brute Force

*/

class TimeMap {
public:
    unordered_map<string, unordered_map<int, vector<string>>> keyStore;
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        keyStore[key][timestamp].push_back(value);
    }

    string get(string key, int timestamp) {
        if (keyStore.find(key) == keyStore.end())
            return "";

        int seen = 0;
        for (const auto& [time, _] : keyStore[key]) {
            if (time <= timestamp) {
                seen = max(seen, time);
            }
        }

        return seen == 0 ? "" : keyStore[key][seen].back();
    }
};

// TC = O(1) for Set, O(N * M) for Get
// SC = O(N * M)
