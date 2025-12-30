
/*
Problem Name   : Count Negative Numbers in a Sorted Matrix
Platform       : LeetCode
Problem Link   : https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/?envType=daily-question&envId=2025-12-30
Type           : Practice
Difficulty     : Easy
Date Solved    : 2025-12-30

Approach:
-

Time Complexity:
Space Complexity:
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int nc = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] < 0)
                    nc++;
            }
        }
        return nc;
    }
};

int main()
{
    Solution s;

    return 0;
}