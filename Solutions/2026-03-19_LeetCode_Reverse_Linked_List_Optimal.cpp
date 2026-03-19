/*

Problem Name   : Reverse Linked List
Platform       : LeetCode
Topic          : Linked List, Recursion
Problem Link   : https://leetcode.com/problems/reverse-linked-list/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-03-19
Approach       : Optimal
Time           : O(N)
Space          : O(1)

*/

using Node = ListNode;
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        Node* temp = head;
        Node* prev = nullptr;
        while(temp){
            Node * front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
};
