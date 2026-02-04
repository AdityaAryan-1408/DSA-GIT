/*

Problem Name   : Last moment all ants fall out
Platform       : GeeksForGeeks
Topic          : Array, Greedy
Problem Link   : https://www.geeksforgeeks.org/problems/last-moment-before-all-ants-fall-out-of-a-plank/1
Type           : POTD
Difficulty     : Medium
Date Solved    : 2026-02-04

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        for (int x : left) {
            ans = max(ans, x);
        }

        for (int x : right) {
            ans = max(ans, n - x);
        }

        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}