/*

Problem Name   : Find Kth Rotation
Platform       : GeeksForGeeks
Topic          : Array
Problem Link   : https://www.geeksforgeeks.org/problems/rotation4723/1
Type           : POTD
Difficulty     : Easy
Date Solved    : 2026-02-09

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findKRotation(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                return i + 1;
            }
        }
        return 0;
    }
};

int main() {
    Solution s;

    return 0;
}