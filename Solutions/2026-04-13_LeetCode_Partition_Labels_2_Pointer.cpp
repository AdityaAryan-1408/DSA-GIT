/*

Problem Name   : Partition Labels
Platform       : LeetCode
Topic          : Hash Table, Two Pointers, String, Greedy
Problem Link   : https://leetcode.com/problems/partition-labels/submissions/1977129431/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-13
Approach       : 2 Pointer
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
        while (i < n) {
            int end = hash[s[i] - 'a'];
            int j = i;
            while (j < end) {
                end = max(end, hash[s[j] - 'a']);
                j++;
            }
            res.push_back(j - i + 1);
            i = j + 1;
        }
        return res;
    }
};
