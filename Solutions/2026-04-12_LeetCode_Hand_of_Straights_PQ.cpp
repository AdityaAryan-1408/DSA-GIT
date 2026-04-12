/*

Problem Name   : Hand of Straights
Platform       : LeetCode
Topic          : Array, Hash Table, Greedy, Sorting
Problem Link   : https://leetcode.com/problems/hand-of-straights/submissions/1976605251/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-12
Approach       : PQ
Time           : O(NlogN)
Space          : O(N)

*/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
            return false;

        unordered_map<int, int> count;
        for (int n : hand)
            count[n] = 1 + count[n];

        priority_queue<int, vector<int>, greater<int>> minH;
        for (auto& pair : count)
            minH.push(pair.first);

        while (!minH.empty()) {
            int first = minH.top();
            for (int i = first; i < first + groupSize; i++) {
                if (count.find(i) == count.end())
                    return false;
                count[i] -= 1;
                if (count[i] == 0) {
                    if (i != minH.top())
                        return false;
                    minH.pop();
                }
            }
        }
        return true;
    }
};
