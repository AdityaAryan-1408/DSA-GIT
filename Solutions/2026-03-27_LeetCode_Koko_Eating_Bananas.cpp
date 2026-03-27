/*

Problem Name   : Koko Eating Bananas
Platform       : LeetCode
Topic          : Array, Binary Search
Problem Link   : https://leetcode.com/problems/koko-eating-bananas/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-27
Time           : O(N log B) where B = max banana
Space          : O(1)

*/

class Solution {
public:
    bool canEat(vector<int>& piles, int mid, int h) {
        int hours = 0;
        for (int& b : piles) {
            hours += b / mid;
            if (b % mid != 0) {
                hours++;
            }
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1, high = *max_element(piles.begin(), end(piles));
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (canEat(piles, mid, h)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
