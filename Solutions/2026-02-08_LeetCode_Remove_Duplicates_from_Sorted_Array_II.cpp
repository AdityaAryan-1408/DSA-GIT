/*

Problem Name   : Remove Duplicates from Sorted Array II
Platform       : LeetCode
Topic          : Top Interview 150, Two Pointer
Problem Link   : https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/?envType=study-plan-v2&envId=top-interview-150
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-02-08

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        int n = nums.size();
        int i = 1;
        int last = nums[0];
        int cntCurr = 1;
        while (i < n) {
            if (cntCurr != 2) {
                if (nums[i] == last) {
                    cntCurr++;
                } else {
                    last = nums[i];
                    cntCurr = 1;
                }
                nums[k] = nums[i];
                k++;

            } else {
                if (nums[i] != last) {
                    nums[k] = nums[i];
                    cntCurr = 1;
                    last = nums[i];
                    k++;
                }
            }
            i++;
        }
        return k;
    }
    int removeDuplicates2(vector<int>& nums) {
        int k = 0;
        for (int x : nums) {
            if (k < 2 || x != nums[k - 2]) {
                nums[k] = x;
                k++;
            }
        }
        return k;
    }
};

int main() {
    Solution s;

    return 0;
}