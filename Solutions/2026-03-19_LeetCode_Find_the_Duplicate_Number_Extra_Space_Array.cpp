/*

Problem Name   : Find the Duplicate Number
Platform       : LeetCode
Topic          : Array, Two Pointers, Binary Search, Bit Manipulation
Problem Link   : https://leetcode.com/problems/find-the-duplicate-number/submissions/1953291921/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-19
Approach       : Extra Space - Array
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> seen(n, 0);
        for(int i = 0; i< n; i++){
            if(seen[nums[i] - 1] == 1) return nums[i];
            seen[nums[i] - 1] = 1;
        }
        return -1;
    }
};

// TC = O(N)
// SC = O(N)
