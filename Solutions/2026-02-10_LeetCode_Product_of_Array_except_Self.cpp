/*

Problem Name   : Product of Array except Self
Platform       : LeetCode
Topic          : Top Interview 150, Prefix Suffix
Problem Link   : https://leetcode.com/problems/product-of-array-except-self/?envType=study-plan-v2&envId=top-interview-150
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-02-10

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);

        int prefix = 1;
        for (int i = 0; i < n; i++) {
            res[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= suffix;
            suffix *= nums[i];
        }
        return res;
    }
};

int main() {
    Solution s;

    return 0;
}