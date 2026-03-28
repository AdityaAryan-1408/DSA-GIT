/*

Problem Name   : Time Based Key-Value Store
Platform       : LeetCode
Topic          : Hash Table, String, Binary Search, Design
Problem Link   : https://leetcode.com/problems/time-based-key-value-store/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-28
Approach       : Optimal - Map

*/

class TimeMap {
public:
    unordered_map<string, map<int, string>> keyStore;
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        keyStore[key].insert({timestamp, value});
    }

    string get(string key, int timestamp) {
        auto it = keyStore[key].upper_bound(timestamp);
        return it == keyStore[key].begin() ? "" : prev(it)->second;
    }
};

// TC = O(n) or O(logN) for Set depending on Language, O(log N) for Get
// SC = O(N * M)
