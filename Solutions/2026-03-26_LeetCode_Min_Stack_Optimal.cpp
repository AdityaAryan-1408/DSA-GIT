/*

Problem Name   : Min Stack
Platform       : LeetCode
Topic          : Stack, Design
Problem Link   : https://leetcode.com/problems/min-stack/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-26
Approach       : Optimal
Time           : O(1)
Space          : O(N)

*/

#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() { mini = LLONG_MAX; }

    void push(int val) {
        long long x = val;

        if (st.empty()) {
            mini = x;
            st.push(x);
        } else {
            if (x >= mini) {
                st.push(x);
            } else {
                st.push(2LL * x - mini); 
                mini = x;
            }
        }
    }

    void pop() {
        if (st.empty())
            return;

        long long x = st.top();
        st.pop();

        if (x < mini) {
            mini = 2LL * mini - x; // restore previous min
        }
    }

    int top() {
        if (st.empty())
            return -1;

        long long x = st.top();
        if (x >= mini)
            return (int)x;
        return (int)mini;
    }

    int getMin() { return (int)mini; }
};
