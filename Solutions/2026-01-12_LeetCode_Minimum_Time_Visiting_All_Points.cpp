/*

Problem Name   : Minimum Time Visiting All Points
Platform       : LeetCode
Topic          : Arrays
Problem Link   : https://leetcode.com/problems/minimum-time-visiting-all-points/description/?envType=daily-question&envId=2026-01-12
Type           : POTD
Difficulty     : Easy
Date Solved    : 2026-01-12

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for (int i = 0; i < points.size() - 1; i++) {
            int currX = points[i][0];
            int currY = points[i][1];
            int targetX = points[i + 1][0];
            int targetY = points[i + 1][1];
            ans += max(abs(targetX - currX), abs(targetY - currY));
        }

        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}