/*

Problem Name   : Permutation in String
Platform       : LeetCode
Topic          : Hash Table, Two Pointers, String, Sliding Window
Problem Link   : https://leetcode.com/problems/permutation-in-string/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-24
Approach       : Optimal
Time           : O(N)
Space          : O(1)

*/

class Solution {
public:
    bool compareHash(vector<int>& hash, vector<int>& check) {
        for (int i = 0; i < 26; i++) {
            if (hash[i] != check[i])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n = s2.size(), m = s1.size();
        int i = 0, j = 0;
        vector<int> hash(26, 0), check(26, 0);
        for (char c : s1)
            hash[c - 'a']++;

        while (j < n) {
            check[s2[j] - 'a']++;
            j++;
            if(j - i== m){
                if(compareHash(hash, check)) return true;
                else{
                    check[s2[i] -'a']--;
                    i++;
                }
            }
        }
        return false;
    }
};
