/*

Problem Name   : Remove K Digits
Platform       : GeeksForGeeks
Topic          : Stack, String
Problem Link   : https://www.geeksforgeeks.org/problems/remove-k-digits/1
Type           : POTD
Difficulty     : Medium
Date Solved    : 2026-01-19

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string removeKdig(string& s, int k) {
        // code here
        stack<char> st;

        for (char c : s) {
            while (!st.empty() && k > 0 && st.top() > c) {
                st.pop();
                k--;
            }
            st.push(c);
        }

        // If still removals left, remove from end
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Build result
        string res = "";
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());

        // Remove leading zeros
        int i = 0;
        while (i < res.size() && res[i] == '0') i++;
        res = res.substr(i);

        return res.empty() ? "0" : res;
    }
};

int main() {
    Solution s;

    return 0;
}