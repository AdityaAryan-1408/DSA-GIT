/*

Problem Name   : Longest Balanced Substring I
Platform       : LeetCode
Topic          : Strings
Problem Link   : https://leetcode.com/problems/longest-balanced-substring-i/description/?envType=daily-question&envId=2026-02-12
Type           : POTD
Difficulty     : Medium
Date Solved    : 2026-02-12

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int longestBalanced(string s) {
        int n = s.size();
        int res = 0;
        vector<int> cnt(26);
        for (int i = 0; i < n; i++) {
            fill(cnt.begin(), cnt.end(), 0);
            for (int j = i; j < n; j++) {
                bool flag = true;
                int c = s[j] - 'a';
                cnt[c]++;
                for (auto x : cnt) {
                    if (x > 0 && x != cnt[c]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    res = max(res, j - i + 1);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;

    return 0;
}