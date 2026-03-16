/*

Problem Name   : Contains Duplicate
Platform       : LeetCode
Topic          : Array, Hash Table, Sorting
Problem Link   : https://leetcode.com/problems/contains-duplicate/submissions/1950492547/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-03-16
Approach       : Brute Force
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i< nums.size() - 1; i++){
            if(nums[i] == nums[i + 1])
                return true;
        }
        return false;
    }
};

TC = O(NlogN)
SC = O(1)
