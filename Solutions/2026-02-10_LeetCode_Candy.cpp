/*

Problem Name   : Candy
Platform       : LeetCode
Topic          : Top Interview 150, Greedy
Problem Link   : https://leetcode.com/problems/candy/description/?envType=study-plan-v2&envId=top-interview-150
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-02-10

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};

int main() {
    Solution s;

    return 0;
}