/*

Problem Name   : Evaluate Reverse Polish Notation
Platform       : LeetCode
Topic          : Array, Math, Stack
Problem Link   : https://leetcode.com/problems/evaluate-reverse-polish-notation/submissions/1952883233/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-19
Approach       : Optimal
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string s : tokens) {
            if (s != "+" && s != "-" && s != "*" && s != "/") {
                st.push(stoi(s));
            }else{
                int first = st.top();
                st.pop(); 
                int second = st.top();
                st.pop();

                if(s == "+") st.push(second + first);  
                if(s == "-") st.push(second - first);  
                if(s == "*") st.push(second * first);  
                if(s == "/") st.push(second / first);  
            }
        }

        return st.top();
    }
};
