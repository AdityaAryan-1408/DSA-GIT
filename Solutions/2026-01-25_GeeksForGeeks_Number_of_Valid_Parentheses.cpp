/*

Problem Name   : Number of Valid Parentheses
Platform       : GeeksForGeeks
Topic          : Combinatorics, DP
Problem Link   : https://www.geeksforgeeks.org/problems/valid-number-of-parenthesis/1
Type           : POTD
Difficulty     : Medium
Date Solved    : 2026-01-25

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findWays(int n) {
        if (n % 2 != 0) {
            return 0;
        }

        int k = n / 2;

        vector<long long> dp(k + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= k; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }

        return dp[k];
    }
};

int main() {
    Solution s;

    return 0;
}