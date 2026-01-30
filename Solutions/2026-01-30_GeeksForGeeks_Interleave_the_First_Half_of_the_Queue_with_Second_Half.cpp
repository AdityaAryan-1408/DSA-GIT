/*

Problem Name   : Interleave the First Half of the Queue with Second Half
Platform       : GeeksForGeeks
Topic          : Queue
Problem Link   : https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1
Type           : POTD
Difficulty     : Medium
Date Solved    : 2026-01-30

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void rearrangeQueue(queue<int>& q) {
        int n = q.size();
        vector<int> first, second;
        int i = 0;
        while (i < n / 2) {
            first.push_back(q.front());
            q.pop();
            i++;
        }
        while (!q.empty()) {
            second.push_back(q.front());
            q.pop();
        }
        for (int i = 0; i < n / 2; i++) {
            q.push(first[i]);
            q.push(second[i]);
        }
    }
};

int main() {
    Solution s;

    return 0;
}