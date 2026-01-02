/*

Problem Name   : N-Repeated Element in Size 2N Array
Platform       : LeetCode
Topic          : Array, HashMap
Problem Link   :
https://leetcode.com/problems/n-repeated-element-in-size-2n-array/description/?envType=daily-question&envId=2026-01-02
Type           : POTD
Difficulty     : Easy
Date Solved    : 2026-01-02

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int x : nums) mp[x]++;
        for (auto& [key, val] : mp) {
            if (val == nums.size() / 2) {
                return key;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;

    return 0;
}