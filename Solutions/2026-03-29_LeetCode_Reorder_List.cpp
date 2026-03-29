/*

Problem Name   : Reorder List
Platform       : LeetCode
Topic          : Linked List, Two Pointers, Stack, Recursion
Problem Link   : https://leetcode.com/problems/reorder-list/submissions/1962694796/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-29
Time           : O(N)
Space          : O(1)

*/

using Node = ListNode;
class Solution {
public:
    Node* reverseList(Node* head) {
        Node* temp = head;
        Node* prev = nullptr;
        while (temp) {
            Node* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    Node* midList(Node* head) {
        Node *slow = head, *fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    void reorderList(ListNode* head) {
        Node* half = midList(head);
        Node* second = half->next;
        half->next = nullptr;
        Node* revHalf = reverseList(second);

        Node *i = head, *j = revHalf;
        while (i && j) {
            Node* ifront = i->next;
            i->next = j;
            Node* jfront = j->next;
            j->next = ifront;
            i = ifront;
            j = jfront;
        }
    }
};
