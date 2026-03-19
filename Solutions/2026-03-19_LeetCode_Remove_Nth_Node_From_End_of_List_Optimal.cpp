/*

Problem Name   : Remove Nth Node From End of List
Platform       : LeetCode
Topic          : Linked List, Two Pointers
Problem Link   : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-19
Approach       : Optimal
Time           : O(N)
Space          : O(1)

*/

using Node = ListNode;
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        Node* dummy = new Node(0);
        dummy->next = head;
        
        Node *fast = dummy, *slow = dummy;
        for (int i = 0; i < n; i++)
            fast = fast->next;
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};
