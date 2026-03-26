/*

Problem Name   : Min Stack
Platform       : LeetCode
Topic          : Stack, Design
Problem Link   : https://leetcode.com/problems/min-stack/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-26
Approach       : Space
Time           : O(1)
Space          : O(N)

*/

class MinStack {
public:
    MinStack() {
    }
    stack<pair<int, int>> st;   
    void push(int val) {
        if(st.empty()){
            st.push({val, val});
        }else{
            st.push({val, min(st.top().second, val)});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

// TC = O(1)
// SC = O(N)
