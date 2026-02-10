/*

Problem Name   : Find the Index of the First Occurrence in a String
Platform       : LeetCode
Topic          : Top Interview 150, String Matching
Problem Link   : https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-02-10

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int strStr(string h, string n) {
        int s1 = h.size();
        int s2 = n.size();
        if (s2 > s1) return -1;

        int i = 0;
        while (i <= s1 - s2) {
            if (h[i] == n[0]) {
                int k = i;
                int j = 0;
                while (j < s2 && h[k] == n[j]) {
                    k++;
                    j++;
                }
                if (j == s2) {
                    return i;
                }
            }
            i++;
        }
        return -1;
    }
};

int main() {
    Solution s;

    return 0;
}