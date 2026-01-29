/*

Problem Name   : Stream First Non-repeating
Platform       : GeeksForGeeks
Topic          : Strings, Queue
Problem Link   : https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
Type           : POTD
Difficulty     : Medium
Date Solved    : 2026-01-29

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string firstNonRepeating(string& s) {
        vector<int> freq(26, 0);
        queue<char> q;
        string ans = "";

        for (char ch : s) {
            freq[ch - 'a']++;
            q.push(ch);

            while (!q.empty() && freq[q.front() - 'a'] > 1) {
                q.pop();
            }

            if (q.empty())
                ans += '#';
            else
                ans += q.front();
        }

        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}