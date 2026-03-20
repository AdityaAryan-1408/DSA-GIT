/*

Problem Name   : Happy Number
Platform       : LeetCode
Topic          : Hash Table, Math, Two Pointers
Problem Link   : https://leetcode.com/problems/happy-number/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-03-20
Approach       : Alternative
Time           : O(1)
Space          : O(1)

*/

class Solution {
public:
    int digSquare(int n) {
        int sq = 0;
        while (n != 0) {
            sq += (n % 10) * (n % 10);
            n /= 10;
        }
        return sq;
    }
    bool isHappy(int n) {
        multiset<int> st;
        int num;
        while (1) {
            num = digSquare(n);
            if (st.find(num) != st.end())
                return false;
            if (num == 1)
                return true;
            st.insert(num);
            n = num;
        }
    }
};
