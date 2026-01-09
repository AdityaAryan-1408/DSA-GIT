/*

Problem Name   : Subarrays With At Most K Distinct Integers
Platform       : GeeksForGeeks
Topic          : Arrays, Sliding Window
Problem Link   : https://www.geeksforgeeks.org/problems/subarrays-with-at-most-k-distinct-integers/1
Type           : POTD
Difficulty     : Medium
Date Solved    : 2026-01-09

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int countAtMostK(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        int l = 0;
        long long ans = 0;

        for (int r = 0; r < arr.size(); r++) {
            freq[arr[r]]++;

            while (freq.size() > k) {
                freq[arr[l]]--;
                if (freq[arr[l]] == 0) freq.erase(arr[l]);
                l++;
            }

            ans += (r - l + 1);
        }

        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}