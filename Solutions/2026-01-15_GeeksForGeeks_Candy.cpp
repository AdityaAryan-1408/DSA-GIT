/*

Problem Name   : Candy
Platform       : GeeksForGeeks
Topic          : Array, Greedy
Problem Link   : https://www.geeksforgeeks.org/problems/candy/1
Type           : POTD
Difficulty     : Medium
Date Solved    : 2026-01-15

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minCandy(vector<int>& arr) {
        int n = arr.size();
        vector<int> candies(n, 1);

        // Left to right
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Right to left
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        return accumulate(candies.begin(), candies.end(), 0);
    }
};

int main() {
    Solution s;

    return 0;
}