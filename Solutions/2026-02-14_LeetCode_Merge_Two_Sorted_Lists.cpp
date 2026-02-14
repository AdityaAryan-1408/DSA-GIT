/*

Problem Name   : Merge Two Sorted Lists
Platform       : LeetCode
Topic          : Top Interview 150, Linked List
Problem Link   : https://leetcode.com/problems/merge-two-sorted-lists/description/?envType=study-plan-v2&envId=top-interview-150
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-02-14

*/

#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node* next;

   public:
    Node() {
        data = 0;
        next = nullptr;
    }
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

   public:
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};
Node* convertToLL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void printLL(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

class Solution {
   public:
    // EXtra Space for new nodes
    Node* mergeTwoLists(Node* list1, Node* list2) {
        Node* dummy = new Node();
        Node* temp = dummy;
        Node* i = list1;
        Node* j = list2;
        while (i && j) {
            if (i->data < j->data) {
                temp->next = new Node(i->data);
                i = i->next;
                temp = temp->next;
            } else {
                temp->next = new Node(j->data);
                j = j->next;
                temp = temp->next;
            }
        }

        while (i) {
            temp->next = new Node(i->data);
            i = i->next;
            temp = temp->next;
        }
        while (j) {
            temp->next = new Node(j->data);
            j = j->next;
            temp = temp->next;
        }
        return dummy->next;
    }
    // No extra space for new nodes, In-place merging
    Node* mergeTwoLists(Node* list1, Node* list2) {
        Node* dummy = new Node();
        Node* temp = dummy;
        Node *i = list1, *j = list2;
        while (i && j) {
            if (i->data < j->data) {
                temp->next = i;
                temp = temp->next;
                i = i->next;
            } else {
                temp->next = j;
                temp = temp->next;
                j = j->next;
            }
        }
        while (i) {
            temp->next = i;
            temp = temp->next;
            i = i->next;
        }
        while (j) {
            temp->next = j;
            temp = temp->next;
            j = j->next;
        }
        return dummy->next;
    }
};

int main() {
    Solution s;

    return 0;
}