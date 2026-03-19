/*

Problem Name   : Merge Two Sorted Lists
Platform       : LeetCode
Topic          : Linked List, Recursion
Problem Link   : https://leetcode.com/problems/merge-two-sorted-lists/submissions/1952955523/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-03-19
Approach       : Recursive
Time           : O(N + M)
Space          : O(1)

*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

// TC = O(N + M)
// SC + O(N + M)
