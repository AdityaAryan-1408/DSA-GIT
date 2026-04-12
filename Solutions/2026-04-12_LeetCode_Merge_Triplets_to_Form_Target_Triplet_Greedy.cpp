/*

Problem Name   : Merge Triplets to Form Target Triplet
Platform       : LeetCode
Topic          : Array, Greedy
Problem Link   : https://leetcode.com/problems/merge-triplets-to-form-target-triplet/submissions/1976732990/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-12
Approach       : Greedy
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int> good;

        for (const auto& t : triplets) {
            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) {
                continue;
            }

            for (int i = 0; i < t.size(); i++) {
                if (t[i] == target[i]) {
                    good.insert(i);
                }
            }
        }
        return good.size() == 3;
    }
};
