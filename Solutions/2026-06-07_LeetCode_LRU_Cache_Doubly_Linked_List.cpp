/*

Problem Name   : LRU Cache
Platform       : LeetCode
Topic          : Hash Table, Linked List, Design, Doubly-Linked List
Problem Link   : https://leetcode.com/problems/lru-cache/submissions/2025124869/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-07
Approach       : Doubly Linked List
Time           : O(Log N)
Space          : O(N)

*/

class LRUCache {
public:
    list<int> dll;
    unordered_map<int, pair<list<int>::iterator, int>> mp;
    int n;
    LRUCache(int capacity) { n = capacity; }

    void makeRecentlyUsed(int key) {
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first = dll.begin();
    }
    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        makeRecentlyUsed(key);
        return mp[key].second;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key].second = value;
            makeRecentlyUsed(key);
        } else {
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            n--;
        }
        if(n < 0){
            int keyDel = dll.back();
            mp.erase(keyDel);
            dll.pop_back();
            n++;
        }
    }
};
