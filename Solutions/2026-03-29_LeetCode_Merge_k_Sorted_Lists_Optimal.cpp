/*

Problem Name   : Merge k Sorted Lists
Platform       : LeetCode
Topic          : Linked List, Divide and Conquer, Heap (Priority Queue), Merge Sort
Problem Link   : https://leetcode.com/problems/merge-k-sorted-lists/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-03-29
Approach       : Optimal
Time           : O(N log K)
Space          : O(1)

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    Node* partitionAndMerge(int start, int end, vector<ListNode*>& lists) {
        if (start == end)
            return lists[start];

        if (start > end)
            return nullptr;

        int mid = start + (end - start) / 2;
        Node* L1 = partitionAndMerge(start, mid, lists);
        Node* L2 = partitionAndMerge(mid + 1, end, lists);
        return mergeTwoLists(L1, L2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return partitionAndMerge(0, lists.size() - 1, lists);
    }
};
