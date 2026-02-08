/*

Problem Name   : Rotate Array
Platform       : LeetCode
Topic          : Top Interview 150, Array
Problem Link   : https://leetcode.com/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-02-08

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.begin() + (n - k));
        reverse(nums.begin() + (n - k), nums.end());
        reverse(nums.begin(), nums.end());
    }
};

int main() {
    Solution s;

    return 0;
}