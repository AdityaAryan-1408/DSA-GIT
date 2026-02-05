/*

Problem Name   : Maximize Number of 1s
Platform       : GeeksForGeeks
Topic          : Sliding Window
Problem Link   : https://www.geeksforgeeks.org/problems/maximize-number-of-1s0905/1https://www.geeksforgeeks.org/problems/maximize-number-of-1s0905/1
Type           : POTD
Difficulty     : Medium
Date Solved    : 2026-02-05

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxOnes(vector<int>& arr, int k) {
        int l = 0, zeros = 0, ans = 0;

        for (int r = 0; r < arr.size(); r++) {
            if (arr[r] == 0) zeros++;

            while (zeros > k) {
                if (arr[l] == 0) zeros--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}