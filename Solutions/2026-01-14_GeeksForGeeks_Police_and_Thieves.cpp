/*

Problem Name   : Police and Thieves
Platform       : GeeksForGeeks
Topic          : Greedy, Two Pointer
Problem Link   : https://www.geeksforgeeks.org/problems/police-and-thieves--141631/1
Type           : POTD
Difficulty     : Medium
Date Solved    : 2026-01-14

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int catchThieves(vector<char>& arr, int k) {
        int n = arr.size();
        vector<int> police, thief;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 'P')
                police.push_back(i);
            else if (arr[i] == 'T')
                thief.push_back(i);
        }

        int i = 0, j = 0, cnt = 0;

        while (i < police.size() && j < thief.size()) {
            if (abs(police[i] - thief[j]) <= k) {
                cnt++;
                i++;
                j++;
            } else if (police[i] < thief[j]) {
                i++;
            } else {
                j++;
            }
        }

        return cnt;
    }
};

int main() {
    Solution s;

    return 0;
}