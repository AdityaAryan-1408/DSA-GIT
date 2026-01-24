/*

Problem Name   : Josephus problem
Platform       : GeeksForGeeks
Topic          : Recursion
Problem Link   : https://www.geeksforgeeks.org/problems/josephus-problem/1
Type           : POTD
Difficulty     : Medium
Date Solved    : 2026-01-24

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int K;

    int helper(vector<int>& nums, int ind) {
        if (nums.size() == 1) return nums[0];

        int kill = (ind + K - 1) % nums.size();
        nums.erase(nums.begin() + kill);
        return helper(nums, kill);
    }

    int josephus(int n, int k) {
        vector<int> nums;
        K = k;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }
        return helper(nums, 0);
    }
};

int main() {
    Solution s;
    int n = 6, k = 2;
    cout << s.josephus(n, k) << endl;
    return 0;
}