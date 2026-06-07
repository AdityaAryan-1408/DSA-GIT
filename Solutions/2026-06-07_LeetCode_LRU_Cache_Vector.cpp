/*

Problem Name   : LRU Cache
Platform       : LeetCode
Topic          : Hash Table, Linked List, Design, Doubly-Linked List
Problem Link   : https://leetcode.com/problems/lru-cache/submissions/2025124869/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-07
Approach       : Vector
Time           : O(Log N)
Space          : O(N)

*/

class LRUCache {
public:
    int n;
    vector<pair<int, int>> cache;
    LRUCache(int capacity) { n = capacity; }

    int get(int key) {
        for (int i = 0; i < cache.size(); i++) {
            if (cache[i].first == key) {
                int val = cache[i].second;
                pair<int, int> temp = cache[i];
                cache.erase(cache.begin() + i);
                cache.push_back(temp);

                return val;
            }
        }
        return -1;
    }

    void put(int key, int value) {
        for (int i = 0; i < cache.size(); i++) {
            if (cache[i].first == key) {
                cache.erase(cache.begin() + i);
                cache.push_back({key, value});
                return;
            }
        }

        if (cache.size() == n) {
            cache.erase(cache.begin());
            cache.push_back({key, value});
        } else {
            cache.push_back({key, value});
        }
    }
};
