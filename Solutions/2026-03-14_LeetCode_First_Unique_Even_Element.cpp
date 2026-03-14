/*

Problem Name   : First Unique Even Element
Platform       : LeetCode
Topic          : Array, Hash
Problem Link   : https://leetcode.com/problems/first-unique-even-element/description/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-03-14
Time           : O(N^2)
Space          : O(N)

*/

class Solution {
public:
    int findIndex(vector<int>& nums, int n) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == n)
                return i;
        }
        return -1;
    }
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int x : nums) {
            if (x % 2 == 0)
                freq[x]++;
        }

        int ind = INT_MAX;
        for (auto& [num, fq] : freq) {
            if (fq == 1) {
                ind = min(ind, findIndex(nums, num));
            }
        }
        if(ind == INT_MAX) return -1;
        return nums[ind];
    }
};
