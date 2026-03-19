/*

Problem Name   : Reverse Linked List
Platform       : LeetCode
Topic          : Linked List, Recursion
Problem Link   : https://leetcode.com/problems/reverse-linked-list/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-03-19
Approach       : Recursive Approach
Time           : O(N)
Space          : O(1)

*/

using Node = ListNode;
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        Node* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
};

// TC = O(N)
// SC = O(Recursive Stack Space) ~ O(N)
