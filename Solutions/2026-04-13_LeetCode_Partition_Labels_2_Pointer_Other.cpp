/*

Problem Name   : Partition Labels
Platform       : LeetCode
Topic          : Hash Table, Two Pointers, String, Greedy
Problem Link   : https://leetcode.com/problems/partition-labels/submissions/1977129431/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-13
Approach       : 2 Pointer Other
Time           : O(N)
Space          : O(26)

*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> res;
        vector<int> hash(26, -1);

        for (int i = 0; i < n; i++) {
            int ind = s[i] - 'a';
            hash[ind] = i;
        }

        int i = 0;
        int start = 0;
        int end = 0;
        while (i < n) {
            end = max(end, hash[s[i] - 'a']);
            if (i == end) {
                res.push_back(end - start + 1);
                start = end + 1;
            }
            i++;
        }
        return res;
    }
};
