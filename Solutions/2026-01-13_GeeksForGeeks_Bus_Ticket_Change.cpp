/*

Problem Name   : Bus Ticket Change
Platform       : GeeksForGeeks
Topic          : Array
Problem Link   : https://www.geeksforgeeks.org/problems/lemonade-change/1
Type           : POTD
Difficulty     : Easy
Date Solved    : 2026-01-13

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool canServe(vector<int>& arr) {
        int five = 0, ten = 0;

        for (int note : arr) {
            if (note == 5) {
                five++;
            } else if (note == 10) {
                if (five == 0) return false;
                five--;
                ten++;
            } else {
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution s;

    return 0;
}