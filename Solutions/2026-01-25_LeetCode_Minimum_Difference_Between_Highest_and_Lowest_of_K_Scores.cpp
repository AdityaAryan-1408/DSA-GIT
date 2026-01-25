/*

Problem Name   : Minimum Difference Between Highest and Lowest of K Scores
Platform       : LeetCode
Topic          : Sliding Window, Sorting
Problem Link   : https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/description/?envType=daily-question&envId=2026-01-25
Type           : POTD
Difficulty     : Easy
Date Solved    : 2026-01-25

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int minDiff = INT_MAX;
        int i = 0, j = k - 1;
        while (j < n) {
            int diff = nums[j] - nums[i];
            minDiff = min(minDiff, diff);
            i++;
            j = i + k - 1;
        }
        return minDiff;
    }
};

int main() {
    Solution s;

    return 0;
}