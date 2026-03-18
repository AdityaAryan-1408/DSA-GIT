/*

Problem Name   : Longest Consecutive Sequence
Platform       : LeetCode
Topic          : Array, Hash Table, Union-Find, Set
Problem Link   : https://leetcode.com/problems/longest-consecutive-sequence/submissions/1952202503/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-18
Approach       : PQ Approach
Time           : O(N)
Space          : O(N)

*/

class Solution2 {
   public:
    int longestConsecutive(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(),
                                                          nums.end());

        if (nums.empty()) return 0;

        int len = 0, cnt = 1;
        int last = pq.top();
        pq.pop();
        while (!pq.empty()) {
            int curr = pq.top();
            pq.pop();

            if (curr == last)
                continue;
            else if (curr == last + 1) {
                cnt++;
            } else {
                len = max(len, cnt);
                cnt = 1;
            }
            last = curr;
        }
        len = max(cnt, len);
        return len;
    }
};

// TC = O(NlogN)
// SC = O(N)
