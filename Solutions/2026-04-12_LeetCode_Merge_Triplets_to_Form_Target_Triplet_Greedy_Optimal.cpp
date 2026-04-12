/*

Problem Name   : Merge Triplets to Form Target Triplet
Platform       : LeetCode
Topic          : Array, Greedy
Problem Link   : https://leetcode.com/problems/merge-triplets-to-form-target-triplet/submissions/1976732990/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-12
Approach       : Greedy Optimal
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool x = false, y = false, z = false;
        for (const auto& t : triplets) {
            x |= (t[0] == target[0] && t[1] <= target[1] && t[2] <= target[2]);
            y |= (t[0] <= target[0] && t[1] == target[1] && t[2] <= target[2]);
            z |= (t[0] <= target[0] && t[1] <= target[1] && t[2] == target[2]);
            if (x && y && z)
                return true;
        }
        return false;
    }
};
