/*

Problem Name   : Find the Duplicate Number
Platform       : LeetCode
Topic          : Array, Two Pointers, Binary Search, Bit Manipulation
Problem Link   : https://leetcode.com/problems/find-the-duplicate-number/submissions/1953291921/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-19
Approach       : Negative Marking
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int num : nums){
            int index = abs(num) - 1;
            if(nums[index] < 0)
                return abs(num);
            
            nums[index] *= -1;
        }
        return -1;
    }
};

// TC = O(N)
// SC = O(1)
