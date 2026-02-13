/*

Problem Name   : All numbers with specific difference
Platform       : GeeksForGeeks
Topic          : Binary Search
Problem Link   : https://www.geeksforgeeks.org/problems/all-numbers-with-specific-difference3558/1
Type           : POTD
Difficulty     : Hard
Date Solved    : 2026-02-13

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool cost(int num, int d) {
        int x = num;
        int sum = 0;
        while (x != 0) {
            sum += x % 10;
            x /= 10;
        }
        return (num - sum >= d);
    }
    int getCount(int n, int d) {
        int low = 1, high = n;
        int ans;
        while (low <= high) {
            cout << "Low : " << low << " High : " << high << endl;
            int mid = low + (high - low) / 2;
            if (cost(mid, d)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return n - ans + 1;
    }
};

int main() {
    Solution s;

    return 0;
}
