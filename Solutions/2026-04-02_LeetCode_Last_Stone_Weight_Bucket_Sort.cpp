/*

Problem Name   : Last Stone Weight
Platform       : LeetCode
Topic          : Array, Heap (Priority Queue)
Problem Link   : https://leetcode.com/problems/last-stone-weight/submissions/1967183982/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-04-02
Approach       : Bucket Sort
Time           : O(N + W)
Space          : O(W)

*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int maxStone = 0;
        for (int stone : stones) {
            maxStone = max(maxStone, stone);
        }

        vector<int> bucket(maxStone + 1, 0);
        for (int stone : stones) {
            bucket[stone]++;
        }

        int first = maxStone, second = maxStone;
        while (first > 0) {
            if (bucket[first] % 2 == 0) {
                first--;
                continue;
            }

            int j = min(first - 1, second);
            while (j > 0 && bucket[j] == 0) {
                j--;
            }

            if (j == 0) {
                return first;
            }

            second = j;
            bucket[first]--;
            bucket[second]--;
            bucket[first - second]++;
            first = max(first - second, second);
        }

        return first;
    }
};
