/*

Problem Name   : Koko Eating Bananas
Platform       : LeetCode
Topic          : Array, Binary Search
Problem Link   : https://leetcode.com/problems/koko-eating-bananas/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-01-04

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int check(vector<int>& piles, int h, int mid) {
        int ans = 0;
        for (int i = 0; i < piles.size(); i++) {
            ans += (piles[i] / mid);
            if (piles[i] % mid != 0) {
                ans++;
            }
        }
        return ans <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low < high) {
            int mid = (low + high) >> 1;
            if (check(piles, h, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main() {
    Solution s;

    return 0;
}