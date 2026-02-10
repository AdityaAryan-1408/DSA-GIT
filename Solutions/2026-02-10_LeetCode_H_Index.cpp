/*

Problem Name   : H-Index
Platform       : LeetCode
Topic          : Top Interview 150, Array, Binary Search
Problem Link   : https://leetcode.com/problems/h-index/?envType=study-plan-v2&envId=top-interview-150
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-02-10

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Approach with O(n) time and O(n) space
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> check(n + 1, 0);
        for (int i = 0; i < n; i++) {
            if (citations[i] >= n) {
                check[n]++;
            } else {
                check[citations[i]]++;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            check[i] += check[i + 1];
        }

        for (int i = n; i >= 0; i--) {
            if (check[i] >= i) return i;
        }
        return -1;
    }

    // Binary Search approach with O(n log n) time and O(1) space
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int maxH = -1;
        sort(citations.begin(), citations.end());
        int maxC = *max_element(citations.begin(), citations.end());
        for (int h = 0; h <= min(n, maxC); h++) {
            int idx = lower_bound(citations.begin(), citations.end(), h) -
                      citations.begin();
            if (n - idx >= h) {
                maxH = max(maxH, h);
            }
        }
        return maxH;
    }
};

int main() {
    Solution s;

    return 0;
}