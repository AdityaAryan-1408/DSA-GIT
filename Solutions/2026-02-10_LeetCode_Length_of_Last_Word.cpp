/*

Problem Name   : Length of Last Word
Platform       : LeetCode
Topic          : Top Interview 150, Strings
Problem Link   : https://leetcode.com/problems/length-of-last-word/?envType=study-plan-v2&envId=top-interview-150
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-02-10

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i = n - 1;
        while (i >= 0 && s[i] == ' ') {
            s.pop_back();
            i--;
        }

        int len = 0;
        while (i >= 0 && s[i] != ' ') {
            len++;
            i--;
        }

        return len;
    }
};

int main() {
    Solution s;

    return 0;
}