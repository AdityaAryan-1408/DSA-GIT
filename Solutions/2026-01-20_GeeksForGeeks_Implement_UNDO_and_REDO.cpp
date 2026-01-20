/*

Problem Name   : Implement UNDO and REDO
Platform       : GeeksForGeeks
Topic          : Stack
Problem Link   : https://www.geeksforgeeks.org/problems/implement-undo-redo/1
Type           : POTD
Difficulty     : Easy
Date Solved    : 2026-01-20

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string res = "";
    stack<char> st;
    void append(char x) { res.push_back(x); }

    void undo() {
        int n = res.size() - 1;
        st.push(res[n]);
        res.pop_back();
    }

    void redo() {
        res.push_back(st.top());
        st.pop();
    }

    string read() { return res; }
};

int main() {
    Solution s;

    return 0;
}