/*

Problem Name   : Longest Consecutive Sequence
Platform       : LeetCode
Topic          : Array, Hash Table, Union-Find, Set
Problem Link   : https://leetcode.com/problems/longest-consecutive-sequence/submissions/1952202503/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-18
Approach       : Optimal
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        unordered_set<int> st(nums.begin(), nums.end());
        int len = 1;
        for(auto num : st){
            int curr = num;
            if(st.find(curr - 1) == st.end()){
                int cnt = 1;
                while(st.find(curr + 1) != st.end()){
                    cnt++;
                    curr++;
                }
                len = max(len, cnt);
            }
        }
        return len;
    }
};

// TC = O(N)
// SC = O(N)
