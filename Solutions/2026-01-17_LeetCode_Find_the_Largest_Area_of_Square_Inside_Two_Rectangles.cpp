/*

Problem Name   : Find the Largest Area of Square Inside Two Rectangles
Platform       : LeetCode
Topic          : Array, Math, Geometry
Problem Link   : https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/description/?envType=daily-question&envId=2026-01-17
Type           : POTD
Difficulty     : Medium
Date Solved    : 2026-01-17

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        int maxSide = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int w = min(topRight[i][0], topRight[j][0]) -
                        max(bottomLeft[i][0], bottomLeft[j][0]);
                int h = min(topRight[i][1], topRight[j][1]) -
                        max(bottomLeft[i][1], bottomLeft[j][1]);

                maxSide = max(maxSide, min(w, h));
            }
        }

        return 1LL * maxSide * maxSide;
    }
};

int main() {
    Solution s;

    return 0;
}