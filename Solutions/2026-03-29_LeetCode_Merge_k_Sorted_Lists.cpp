/*

Problem Name   : Merge k Sorted Lists
Platform       : LeetCode
Topic          : Linked List, Divide and Conquer, Heap (Priority Queue), Merge Sort
Problem Link   : https://leetcode.com/problems/merge-k-sorted-lists/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-03-29
Time           : O(NK) - Number of Nodes in all lists * Number of Lists
Space          : O(1)

*/

using Node = ListNode;
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if (!a)
            return b;
        if (!b)
            return a;

        Node* head;
        if (a->val <= b->val) {
            head = a;
            a = a->next;
        } else {
            head = b;
            b = b->next;
        }

        Node* tail = head;
        while (a && b) {
            if (a->val <= b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = (a ? a : b);
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        if(n == 0) return nullptr;
        
        for(int i = 1; i < n; i++){
            lists[i] = mergeTwoLists(lists[i - 1], lists[i]);
        }
        return lists[n - 1];
    }
};
