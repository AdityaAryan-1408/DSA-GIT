/*

Problem Name   : Minimum Pair Removal to Sort Array I
Platform       : LeetCode
Topic          : Array
Problem Link   : https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/description/?envType=daily-question&envId=2026-01-22
Type           : POTD
Difficulty     : Easy
Date Solved    : 2026-01-22

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isSorted(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) return false;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;
        while (!isSorted(nums)) {
            int n = nums.size();
            int minSum = INT_MAX;
            int ind = -1;
            for (int i = 0; i < n - 1; i++) {
                int sum = nums[i] + nums[i + 1];
                if (sum < minSum) {
                    minSum = sum;
                    ind = i;
                }
            }
            nums[ind] = nums[ind + 1] + nums[ind];
            nums.erase(nums.begin() + ind + 1);
            ops++;
        }
        return ops;
    }
};

int main() {
    Solution s;

    return 0;
}