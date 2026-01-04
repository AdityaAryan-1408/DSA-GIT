/*

Problem Name   : Four Divisors
Platform       : LeetCode
Topic          : Math
Problem Link   :
https://leetcode.com/problems/four-divisors/description/?envType=daily-question&envId=2026-01-04
Type           : POTD
Difficulty     : Medium
Date Solved    : 2026-01-04

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int divCount(int n) {
        int d = 0, ds = 0;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                ds += i;
                d++;
                if (d > 4) return 0;
            }
        }
        if (d == 4) return ds;
        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += divCount(num);
        }
        return sum;
    }
};

int main() {
    Solution s;

    return 0;
}