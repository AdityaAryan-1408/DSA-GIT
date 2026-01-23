/*

Problem Name   : Linear Search
Platform       : GeeksForGeeks
Topic          : Array, Searching
Problem Link   : https://www.geeksforgeeks.org/problems/search-an-element-in-an-array-1587115621/1
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-01-23

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int search(vector<int>& arr, int x) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == x) return i;
        }
        return -1;
    }
};

int main() {
    Solution s;

    return 0;
}