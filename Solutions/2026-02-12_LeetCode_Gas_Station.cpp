/*

Problem Name   : Gas Station
Platform       : LeetCode
Topic          : Top Interview 150, Greedy
Problem Link   : https://leetcode.com/problems/gas-station/description/?envType=study-plan-v2&envId=top-interview-150
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-02-12

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int n;
    // Time Complexity: O(n^2) 2 loops approach
    bool isPossible(vector<int>& gas, vector<int>& cost, int start) {
        int tank = gas[start];
        tank -= cost[start];
        int i = (start + 1) % n;
        while (i != start) {
            tank += gas[i];
            tank -= cost[i];
            if (tank <= 0) {
                if (tank == 0 && ((i + 1) % n == start)) return true;
                return false;
            }
            i = (i + 1) % n;
        }
        return true;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        n = gas.size();
        for (int i = 0; i < n; i++) {
            if (gas[i] < cost[i])
                continue;
            else {
                int start = i;
                if (isPossible(gas, cost, start)) return i;
            }
        }
        return -1;
    }

    // Time Complexity: O(n) 1 loop approach
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = accumulate(gas.begin(), gas.end(), 0);
        int totalCost = accumulate(cost.begin(), cost.end(), 0);
        if (totalCost > totalGas) {
            return -1;
        }

        int potentialStart = 0;
        int currentTank = 0;
        for (int i = 0; i < gas.size(); i++) {
            currentTank += gas[i];
            currentTank -= cost[i];

            if (currentTank < 0) {
                potentialStart = i + 1;
                currentTank = 0;
            }
        }

        return potentialStart;
    }
};

int main() {
    Solution s;

    return 0;
}