/*

Problem Name   : Merge Two Sorted Lists
Platform       : LeetCode
Topic          : Linked List, Recursion
Problem Link   : https://leetcode.com/problems/merge-two-sorted-lists/submissions/1952955523/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-03-19
Approach       : Optimal
Time           : O(N + M)
Space          : O(1)

*/

using Node = ListNode;
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        Node* head;
        if (list1->val <= list2->val) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }

        Node* tail = head;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        tail->next = (list1 ? list1 : list2);
        return head;
    }
};
