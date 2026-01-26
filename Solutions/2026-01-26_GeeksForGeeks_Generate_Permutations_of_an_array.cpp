/*

Problem Name   : Generate Permutations of an array
Platform       : GeeksForGeeks
Topic          : Array, Recursion
Problem Link   : https://www.geeksforgeeks.org/problems/generate-permutations-of-an-array/1
Type           : POTD
Difficulty     : Easy
Date Solved    : 2026-01-26

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> permuteDist(vector<int>& arr) {
        vector<vector<int>> res;
        vector<int> check = arr;
        next_permutation(check.begin(), check.end());
        res.push_back(check);
        while (check != arr) {
            next_permutation(check.begin(), check.end());
            res.push_back(check);
        }
        return res;
    }
};

int main() {
    Solution s;

    return 0;
}