/*

Problem Name   : Hand of Straights
Platform       : LeetCode
Topic          : Array, Hash Table, Greedy, Sorting
Problem Link   : https://leetcode.com/problems/hand-of-straights/submissions/1976605251/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-12
Approach       : Map
Time           : O(NlogN)
Space          : O(N)

*/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0)
            return false;

        map<int, int> mp;
        for (int& handNum : hand)
            mp[handNum]++;

        while (!mp.empty()) {
            int curr = mp.begin()->first;

            for (int i = 0; i < groupSize; i++) {
                if (mp[curr + i] == 0)
                    return false;

                mp[curr + i]--;
                if (mp[curr + i] < 1)
                    mp.erase(curr + i);
            }
        }
        return true;
    }
};
// TC = O(NLOGN + N * groupSize)
// SC = O(N)
