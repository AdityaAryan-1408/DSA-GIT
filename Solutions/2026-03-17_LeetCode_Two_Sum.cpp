/*

Problem Name   : Two Sum
Platform       : LeetCode
Topic          : Array, Hash Table, Sorting
Problem Link   : https://leetcode.com/problems/two-sum/submissions/1950900858/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-03-17
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int res = target - nums[i];
            if (mp.find(res) != mp.end())
                return {i, mp[res]};
            mp[nums[i]] = i;
        }
        return {-1, -1};
    }
};
