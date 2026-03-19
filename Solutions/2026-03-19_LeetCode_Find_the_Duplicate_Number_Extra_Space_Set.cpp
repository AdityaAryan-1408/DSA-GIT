/*

Problem Name   : Find the Duplicate Number
Platform       : LeetCode
Topic          : Array, Two Pointers, Binary Search, Bit Manipulation
Problem Link   : https://leetcode.com/problems/find-the-duplicate-number/submissions/1953291921/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-19
Approach       : Extra Space - Set
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(int x : nums){
            if(st.find(x) != st.end()){
                return x;
            }
            st.insert(x);
        }
        return -1;
    }
};

// TC = O(N)
// SC = O(N)
