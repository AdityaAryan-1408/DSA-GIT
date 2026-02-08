/*

Problem Name   : Remove Duplicates from Sorted Array
Platform       : LeetCode
Topic          : Top Interview 150, Two Pointer
Problem Link   : https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-02-08

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {  // STL approach
        set<int> st(nums.begin(), nums.end());
        nums.assign(st.begin(), st.end());
        return st.size();
    }

    int removeDuplicates2(vector<int>& nums) {  // Two Pointer approach
        int k = 1;
        int n = nums.size();
        int i = 1;
        int last = nums[0];
        while (i < n) {
            if (nums[i] != last) {
                nums[k] = nums[i];
                last = nums[i];
                k++;
            }
            i++;
        }
        return k;
    }
};

int main() {
    Solution s;

    return 0;
}