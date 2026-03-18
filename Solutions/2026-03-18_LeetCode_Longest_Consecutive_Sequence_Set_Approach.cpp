/*

Problem Name   : Longest Consecutive Sequence
Platform       : LeetCode
Topic          : Array, Hash Table, Union-Find, Set
Problem Link   : https://leetcode.com/problems/longest-consecutive-sequence/submissions/1952202503/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-18
Approach       : Set Approach
Time           : O(N)
Space          : O(N)

*/

class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        int len = 0;
        int cnt = 1;

        for (auto it : st) {
            cout << it << " ";
        }
        cout << endl;

        for (auto it = st.begin(); it != prev(st.end()); ++it) {
            auto nextIt = next(it);
            cout << *it << " " << *nextIt << endl;
            if (*nextIt - *it == 1) {
                cout << "Executed" << endl;
                cnt++;
            } else {
                len = max(cnt, len);
                cnt = 1;
            }
        }
        len = max(cnt, len);
        return len;
    }
};

// TC = O(NlogN)
// SC = O(N)
