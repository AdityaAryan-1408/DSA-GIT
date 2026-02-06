/*

Problem Name   : Minimum Removals to Balance Array
Platform       : LeetCode
Topic          : Binary Search
Problem Link   : https://leetcode.com/problems/minimum-removals-to-balance-array/description/?envType=daily-question&envId=2026-02-06
Type           : POTD
Difficulty     : Medium
Date Solved    : 2026-02-06

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int minCheck = INT_MAX;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            long long check = 1LL * nums[i] * k;
            int ind =
                upper_bound(nums.begin(), nums.end(), check) - nums.begin();
            minCheck = min(minCheck, n - (ind - i));
        }
        return minCheck;
    }
};

int main() {
    Solution s;

    return 0;
}