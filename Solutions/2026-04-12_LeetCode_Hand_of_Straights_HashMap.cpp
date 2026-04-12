/*

Problem Name   : Hand of Straights
Platform       : LeetCode
Topic          : Array, Hash Table, Greedy, Sorting
Problem Link   : https://leetcode.com/problems/hand-of-straights/submissions/1976605251/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-12
Approach       : HashMap
Time           : O(NlogN)
Space          : O(N)

*/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        unordered_map<int, int> count;
        for (int num : hand) count[num]++;

        for (int num : hand) {
            int start = num;
            while (count[start - 1] > 0) start--;
            while (start <= num) {
                while (count[start] > 0) {
                    for (int i = start; i < start + groupSize; i++) {
                        if (count[i] == 0) return false;
                        count[i]--;
                    }
                }
                start++;
            }
        }
        return true;
    }
};
