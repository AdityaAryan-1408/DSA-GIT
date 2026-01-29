/*

Problem Name   : Find The First Player to win K Games in a Row
Platform       : LeetCode
Topic          : Array, Deque
Problem Link   : https://leetcode.com/problems/find-the-first-player-to-win-k-games-in-a-row/description/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-01-29

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();

        if (k >= n - 1) {
            int maxSkill = -1, ans = 0;
            for (int i = 0; i < n; i++) {
                if (skills[i] > maxSkill) {
                    maxSkill = skills[i];
                    ans = i;
                }
            }
        }
        int currentWinner = 0;
        int winCount = 0;
        for (int i = 1; i < n; i++) {
            if (skills[currentWinner] > skills[i]) {
                winCount++;
            } else {
                currentWinner = i;
                winCount = 1;
            }
            if (winCount == k) {
                return currentWinner;
            }
        }
        if (winCount < k) {
            return currentWinner;
        }
        return -1;
    }
};

int main() {
    Solution s;

    return 0;
}