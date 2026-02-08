/*

Problem Name   : Majority Element
Platform       : LeetCode
Topic          : Top Interview 150, Two Pointer
Problem Link   : https://leetcode.com/problems/majority-element/description/?envType=study-plan-v2&envId=top-interview-150
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-02-08

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // STL approach with O(n) time and O(n) space due to the unordered_map
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int x : nums) mp[x]++;
        for (auto it : mp) {
            if (it.second > n / 2) return it.first;
        }
        return -1;
    }
    // Approach where guaranteed majority element is present, Moore's Voting Algorithm with O(n) time and O(1) space
    int majorityElement(vector<int>& nums) {
        int element;
        int votes = 0;
        for (int x : nums) {
            if (votes == 0) {
                votes = 1;
                element = x;
            } else if (x == element)
                votes++;
            else
                votes--;
        }
        return element;
    }

    // Approach where majority element may not be present, Moore's Voting Algorithm with O(n) time and O(1) space
    int majorityElement(vector<int>& nums) {
        int element;
        int votes = 0;
        for (int x : nums) {
            if (votes == 0) {
                votes = 1;
                element = x;
            } else if (x == element)
                votes++;
            else
                votes--;
        }
        int valid = 0;
        for (int y : nums) {
            if (y == element) valid++;
        }
        return valid > nums.size() / 2 ? element : -1;
    }
};

int main() {
    Solution s;

    return 0;
}