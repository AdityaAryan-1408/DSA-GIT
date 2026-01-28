/*

Problem Name   : Alternating Groups I
Platform       : LeetCode
Topic          : Array
Problem Link   : https://leetcode.com/problems/alternating-groups-i/description/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-01-28

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        int i = 0;
        int groups = 0;
        while (i < n) {
            int first = colors[i];
            int mid = colors[(i + 1) % n];
            int second = colors[(i + 2) % n];

            if ((first == 0 && mid == 1 && second == 0) ||
                (first == 1 && mid == 0 && second == 1))
                groups++;

            i++;
        }
        return groups;
    }
};

int main() {
    Solution s;

    return 0;
}