/*

Problem Name   : Expression contains redundant bracket or not
Platform       : GeeksForGeeks
Topic          : Stack, String
Problem Link   : https://www.geeksforgeeks.org/problems/expression-contains-redundant-bracket-or-not/1
Type           : POTD
Difficulty     : Medium
Date Solved    : 2026-01-17

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool checkRedundancy(string& s) {
        // code here
        stack<char> st;

        for (char ch : s) {
            if (ch == ')') {
                bool hasOperator = false;

                while (!st.empty() && st.top() != '(') {
                    char top = st.top();
                    st.pop();

                    if (top == '+' || top == '-' || top == '*' || top == '/')
                        hasOperator = true;
                }

                // Pop the opening '('
                if (!st.empty()) st.pop();

                // If no operator found, parentheses are redundant
                if (!hasOperator) return true;
            } else {
                st.push(ch);
            }
        }

        return false;
    }
};

int main() {
    Solution s;

    return 0;
}