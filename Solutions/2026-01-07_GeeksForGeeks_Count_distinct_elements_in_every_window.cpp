/*

Problem Name   : Count distinct elements in every window
Platform       : GeeksForGeeks
Topic          : Array, Hashing
Problem Link   : https://www.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1
Type           : POTD
Difficulty     : Medium
Date Solved    : 2026-01-07

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> countDistinct(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> result;
        unordered_map<int, int> mp;

        for (int i = 0; i < k; i++) {
            mp[arr[i]]++;
        }
        result.push_back(mp.size());

        for (int i = k; i < n; i++) {
            mp[arr[i - k]]--;
            if (mp[arr[i - k]] == 0) {
                mp.erase(arr[i - k]);
            }

            mp[arr[i]]++;
            result.push_back(mp.size());
        }

        return result;
    }
};

int main() {
    Solution s;

    return 0;
}