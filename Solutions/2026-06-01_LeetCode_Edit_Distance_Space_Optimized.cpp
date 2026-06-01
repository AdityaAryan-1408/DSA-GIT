/*

Problem Name   : Edit Distance
Platform       : LeetCode
Topic          : String, Dynamic Programming
Problem Link   : https://leetcode.com/problems/edit-distance/submissions/2019028470/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-01
Approach       : Space Optimized
Time           : O(N * M)
Space          : O(N * M)

*/

class Solution {
public:
    int minDistance(string& a, string& b) {
        int n = a.size(), m = b.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        for (int j = 0; j <= m; j++)
            prev[j] = j;
        for (int i = 1; i <= n; i++) {
            curr[0] = i;
            for (int j = 1; j <= m; j++) {
                if (a[i - 1] == b[j - 1])
                    curr[j] = 0 + prev[j - 1];
                else {
                    int ins = 1 + curr[j - 1];
                    int del = 1 + prev[j];
                    int rep = 1 + prev[j - 1];
                    curr[j] = min({ins, del, rep});
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};
