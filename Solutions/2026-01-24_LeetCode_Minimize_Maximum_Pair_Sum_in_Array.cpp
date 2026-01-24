/*

Problem Name   : Minimize Maximum Pair Sum in Array
Platform       : LeetCode
Topic          : Two Pointer, Greedy, Sorting
Problem Link   : https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/description/?envType=daily-question&envId=2026-01-24
Type           : POTD
Difficulty     : Medium
Date Solved    : 2026-01-24

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0, j = n - 1;
        int maxPair = INT_MIN;
        while (i < j) {
            int pairSum = nums[i] + nums[j];
            maxPair = max(maxPair, pairSum);
            i++, j--;
        }
        return maxPair;
    }
};

int main() {
    Solution s;

    return 0;
}