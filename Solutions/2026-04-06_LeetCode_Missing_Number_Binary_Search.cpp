/*

Problem Name   : Missing Number
Platform       : LeetCode
Topic          : Array, Hash Table, Math, Binary Search, Bit Manipulation, Sorting
Problem Link   : https://leetcode.com/problems/missing-number/submissions/1970745291/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-04-06
Approach       : Binary Search
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = n;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > mid) {
                res = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return res;
    }
};

/ TC = O(NlogN)
// SC = O(1)
