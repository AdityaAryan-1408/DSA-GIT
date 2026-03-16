/*

Problem Name   : Contains Duplicate
Platform       : LeetCode
Topic          : Array, Hash Table, Sorting
Problem Link   : https://leetcode.com/problems/contains-duplicate/submissions/1950492547/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-03-16
Approach       : Optimal
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> mp;
        for(int x: nums) mp[x]++;
        for(auto it: mp){
            if(it.second >= 2) return true; 
        }
        return false;
    }
};
