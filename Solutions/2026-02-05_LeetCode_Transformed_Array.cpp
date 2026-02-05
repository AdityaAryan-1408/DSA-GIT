/*

Problem Name   : Transformed Array
Platform       : LeetCode
Topic          : Array
Problem Link   : https://leetcode.com/problems/transformed-array/description/?envType=daily-question&envId=2026-02-05
Type           : POTD
Difficulty     : Easy
Date Solved    : 2026-02-05

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                int ind = (i + nums[i]) % n;
                res[i] = nums[ind];
            } else if (nums[i] < 0) {
                int ind = (n + (i + nums[i]) % n) % n;
                res[i] = nums[ind];
            } else {
                res[i] = nums[i];
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    
    return 0;
}