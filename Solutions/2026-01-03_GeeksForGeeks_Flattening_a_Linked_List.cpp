/*

Problem Name   : Flattening a Linked List
Platform       : GeeksForGeeks
Topic          : Linked List
Problem Link   :
https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1 Type : POTD
Difficulty     : Medium
Date Solved    : 2026-01-03

*/

#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution {
   public:
    Node* flatten(Node* root) {
        priority_queue<int, vector<int>, greater<int>> q;
        Node* temp = root;
        while (temp != nullptr) {
            Node* curr = temp->bottom;
            while (curr != nullptr) {
                q.push(curr->data);
                curr = curr->bottom;
            }
            q.push(temp->data);
            temp = temp->next;
        }
        if (q.empty()) return nullptr;
        Node* newList = new Node(q.top());
        q.pop();
        Node* t = newList;
        while (!q.empty()) {
            Node* newNode = new Node(q.top());
            q.pop();
            t->bottom = newNode;
            t = newNode;
        }
        t->bottom = nullptr;
        return newList;
    }
};

int main() {
    Solution s;

    return 0;
}