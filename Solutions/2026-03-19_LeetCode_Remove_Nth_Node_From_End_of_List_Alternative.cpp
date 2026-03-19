/*

Problem Name   : Remove Nth Node From End of List
Platform       : LeetCode
Topic          : Linked List, Two Pointers
Problem Link   : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-19
Approach       : Alternative
Time           : O(N)
Space          : O(1)

*/

using Node = ListNode;
class Solution {
public:
    int listLen(Node* head) {
        int len = 0;
        Node* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = listLen(head);
        if (len == 1)
            return nullptr;

        n = len - n + 1;
        if(n == 1) return head->next;
        
        Node* temp = head;
        Node* prev = nullptr;
        int cnt = 0;
        while (temp) {
            if (cnt == n - 1) {
                prev->next = temp->next;
                break;
            }
            prev = temp;
            temp = temp->next;
            cnt++;
        }
        return head;
    }
};

// TC = O(2N) 2 passes, not optimal.
// SC = O(1)
