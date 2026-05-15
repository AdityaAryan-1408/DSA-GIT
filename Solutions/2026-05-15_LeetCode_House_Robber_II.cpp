/*

Problem Name   : House Robber II
Platform       : LeetCode
Topic          : Array, Dynamic Programming
Problem Link   : https://leetcode.com/problems/house-robber-ii/submissions/2003722742/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-15
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    int helper(vector<int>& nums) {
        int n = nums.size();
        int prev1 = nums[0];
        int prev2 = 0, curi;
        int pick, notPick;
        for (int i = 1; i < n; i++) {
            pick = nums[i];
            if (i > 1)
                pick += prev2;

            notPick = 0 + prev1;
            curi = max(pick, notPick);
            prev2 = prev1;
            prev1 = curi;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        vector<int> temp1, temp2;
        int n = nums.size();
        if(n==1)
            return nums[0];
        for (int i = 0; i < n; i++) {
            if (i != 0)
                temp1.push_back(nums[i]);
            if (i != n - 1)
                temp2.push_back(nums[i]);
        }
        return max(helper(temp1), helper(temp2));
    }
};
