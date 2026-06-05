/*

Problem Name   : Longest Increasing Subsequence
Platform       : LeetCode
Topic          : Array, Binary Search, Dynamic Programming
Problem Link   : https://leetcode.com/problems/longest-increasing-subsequence/submissions/2022964327/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-05
Approach       : Binary Search
Time           : O(N * P)
Space          : O(N * P)

*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i = 1; i< n; i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
            }else{
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return temp.size();
    }
};
