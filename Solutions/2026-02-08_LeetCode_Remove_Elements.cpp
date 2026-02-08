/*

Problem Name   : Remove Elements
Platform       : LeetCode
Topic          : Top Interview 150, Two Pointer
Problem Link   : https://leetcode.com/problems/remove-element/?envType=study-plan-v2&envId=top-interview-150
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-02-08

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {  // 3 Passes
        int n = nums.size();
        int i = 0, j = n - 1;
        int cnt = count(nums.begin(), nums.end(), val);
        if (cnt == n) {
            nums.clear();
            return 0;
        }
        while (i < j) {
            if (nums[i] == val) {
                while (nums[j] == val && j > i) j--;
                swap(nums[i], nums[j]);

                j--;
            }
            i++;
        }
        while (cnt != 0) {
            nums.pop_back();
            cnt--;
        }
        return nums.size();
    }
    int removeElement2(vector<int>& nums, int val) {  // 2 Passes
        int n = nums.size();
        int i = 0, j = n - 1;
        int cnt = count(nums.begin(), nums.end(), val);
        if (cnt == n) {
            nums.clear();
            return 0;
        }
        while (i < j) {
            if (nums[i] == val) {
                while (nums[j] == val && j > i) j--;
                swap(nums[i], nums[j]);

                j--;
            }
            i++;
        }

        return n - cnt;
    }
    int removeElement3(vector<int>& nums, int val) {  // 1 Pass
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 3};
    int val = 3;
    cout << s.removeElement(nums, val) << endl;
    return 0;
}