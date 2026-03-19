/*

Problem Name   : Find the Duplicate Number
Platform       : LeetCode
Topic          : Array, Two Pointers, Binary Search, Bit Manipulation
Problem Link   : https://leetcode.com/problems/find-the-duplicate-number/submissions/1953291921/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-19
Approach       : Sorting
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i< nums.size() - 1; i++){
            if(nums[i] == nums[i + 1]) return nums[i];
        }
        return -1;
    }
};

// TC = O(NlogN)
// SC = O(1)
