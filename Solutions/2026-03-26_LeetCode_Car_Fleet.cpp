/*

Problem Name   : Car Fleet
Platform       : LeetCode
Topic          : Array, Stack, Sorting, Monotonic Stack
Problem Link   : https://leetcode.com/problems/car-fleet/submissions/1960138182/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-26
Time           : O(NlogN)
Space          : O(N)

*/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pair;
        for (int i = 0; i < position.size(); i++) {
            pair.push_back({position[i], speed[i]});
        }
        sort(pair.rbegin(), pair.rend());
        vector<double> stack;
        for (auto& p : pair) {
            stack.push_back((double)(target - p.first) / p.second);
            if (stack.size() >= 2 &&
                stack.back() <= stack[stack.size() - 2])
            {
                stack.pop_back();
            }
        }
        return stack.size();
    }
};
