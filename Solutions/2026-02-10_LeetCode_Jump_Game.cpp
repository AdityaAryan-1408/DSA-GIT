/*

Problem Name   : Jump Game
Platform       : LeetCode
Topic          : Top Interview 150, Greedy
Problem Link   : https://leetcode.com/problems/jump-game/description/?envType=study-plan-v2&envId=top-interview-150
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-02-10

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxInd = 0;
        for (int i = 0; i < n; i++) {
            if (i > maxInd) return false;
            maxInd = max(maxInd, i + nums[i]);
        }
        return true;
    }
};

int main() {
    Solution s;

    return 0;
}