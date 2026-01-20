/*

Problem Name   : Add numbers in Linked List
Platform       : GeeksForGeeks
Topic          : Linked List
Problem Link   : https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1?page=1&status=unsolved&sortBy=submissions
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-01-20

*/

#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node* next;

   public:
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
    Node* removeLeadingZeros(Node* head) {
        while (head != nullptr && head->data == 0) {
            head = head->next;
        }
        return head == nullptr ? new Node(0) : head;
    }
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;

        while (curr != nullptr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }
    Node* addTwoLists(Node* head1, Node* head2) {
        Node* rev1 = reverseList(head1);
        Node* rev2 = reverseList(head2);
        int carry = 0;
        Node* temp1 = rev1;
        Node* temp2 = rev2;
        Node* newNode = new Node(0);
        Node* curr = newNode;
        while (temp1 != nullptr && temp2 != nullptr) {
            int d = temp1->data + temp2->data + carry;
            if (d >= 10) {
                carry = d / 10;
                d = d % 10;
            } else {
                carry = 0;
            }
            curr->next = new Node(d);
            curr = curr->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        while (temp1 != nullptr) {
            int d = temp1->data + carry;
            if (d >= 10) {
                carry = d / 10;
                d = d % 10;
            } else {
                carry = 0;
            }
            curr->next = new Node(d);
            curr = curr->next;
            temp1 = temp1->next;
        }

        while (temp2 != nullptr) {
            int d = temp2->data + carry;
            if (d >= 10) {
                carry = d / 10;
                d = d % 10;
            } else {
                carry = 0;
            }
            curr->next = new Node(d);
            curr = curr->next;
            temp2 = temp2->next;
        }

        if (carry != 0) {
            curr->next = new Node(carry);
            curr = curr->next;
        }
        Node* res = reverseList(newNode->next);
        return removeLeadingZeros(res);
    }
};

int main() {
    Solution s;

    return 0;
}