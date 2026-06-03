/*

Problem Name   : Regular Expression Matching
Platform       : LeetCode
Topic          : String, Dynamic Programming, Recursion
Problem Link   : https://leetcode.com/problems/regular-expression-matching/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-06-03
Approach       : Recursion
Time           : O(N * M)
Space          : O(N * M)

*/

class Solution {
public:
    bool helper(string s, string p){
        if(p.size() == 0){
            return s.size() == 0;
        }

        bool firstMatch = (s.size()> 0 && (p[0] == s[0] || p[0] == '.'));
        if(p[1] == '*'){
            bool notTake = helper(s, p.substr(2));
            bool take = firstMatch && helper(s.substr(1), p);

            return take || notTake;
        }
        return firstMatch && helper(s.substr(1), p.substr(1));
    }
    bool isMatch(string s, string p) {
        return helper(s, p);
    }
};
