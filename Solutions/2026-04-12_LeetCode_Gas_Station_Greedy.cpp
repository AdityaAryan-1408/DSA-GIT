/*

Problem Name   : Gas Station
Platform       : LeetCode
Topic          : Array, Greedy
Problem Link   : https://leetcode.com/problems/gas-station/submissions/1976147599/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-12
Approach       : Greedy
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
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
