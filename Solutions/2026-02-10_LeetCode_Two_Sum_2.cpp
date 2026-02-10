/*

Problem Name   : Two Sum 2
Platform       : LeetCode
Topic          : Top Interview 150, Array
Problem Link   : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/?envType=study-plan-v2&envId=top-interview-150
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-02-10

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while (left <= right) {
            if (numbers[left] + numbers[right] == target)
                return {left + 1, right + 1};

            else if (numbers[left] + numbers[right] > target)
                right--;
            else
                left++;
        }

        return {-1, -1};
    }
};

int main() {
    Solution s;

    return 0;
}