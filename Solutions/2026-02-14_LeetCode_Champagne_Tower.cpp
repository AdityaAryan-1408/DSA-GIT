/*

Problem Name   : Champagne Tower
Platform       : LeetCode
Topic          : Array, DP, Simulation
Problem Link   : https://leetcode.com/problems/champagne-tower/description/?envType=daily-question&envId=2026-02-14
Type           : POTD
Difficulty     : Medium
Date Solved    : 2026-02-14

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    /* 
    Simulate the pouring of champagne into the glasses.
    Each glass can hold 1 unit of champagne, and any excess champagne will spill over to the glasses below it.
    We use a 2D vector to represent the glasses and their current amount of champagne. We iterate through each row of glasses,
    calculating the excess champagne and distributing it to the glasses in the next row. Finally, we return the amount of
    champagne in the queried glass, ensuring that it does not exceed 1 unit.
    */
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> glass(102, vector<double>(102, 0));
        glass[0][0] = poured;
        for (int i = 0; i < query_row; i++) {
            for (int j = 0; j <= i; j++) {
                double g = (glass[i][j] - 1.0) / 2.0;
                if (g > 0) {
                    glass[i + 1][j] += g;
                    glass[i + 1][j + 1] += g;
                }
            }
        }

        return min(1.0, glass[query_row][query_glass]);
    }
};

int main() {
    Solution s;

    return 0;
}