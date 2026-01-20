/*

Problem Name   : Construct the Minimum Bitwise Array I
Platform       : LeetCode
Topic          : Bit Manipulation
Problem Link   : https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/description/?envType=daily-question&envId=2026-01-20
Type           : POTD
Difficulty     : Easy
Date Solved    : 2026-01-20

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int tmp = nums[i];
            for (int j = 1; j < nums[i]; j++) {
                if ((j | (j + 1)) == nums[i]) {
                    nums[i] = j;
                    break;
                }
            }
            if (nums[i] == tmp) {
                nums[i] = -1;
            }
        }
        return nums;
    }
};

int main() {
    Solution s;

    return 0;
}