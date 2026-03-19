/*

Problem Name   : Add Two Numbers
Platform       : LeetCode
Topic          : Linked List, Math, Recursion
Problem Link   : https://leetcode.com/problems/add-two-numbers/submissions/1953205202/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-19
Approach       : Alternative
Time           : O(N + M)
Space          : O(max(N, M))

*/

using Node = ListNode;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        Node *i = l1, *j = l2;
        Node* dummy = new Node(0);
        Node* temp = dummy;
        while (i && j) {
            int sum = i->val + j->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            temp->next = new Node(sum);
            temp = temp->next;
            i = i->next;
            j = j->next;
        }

        while (i) {
            int sum = i->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            temp->next = new Node(sum);
            temp = temp->next;
            i = i->next;
        }
        while (j) {
            int sum = j->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            temp->next = new Node(sum);
            temp = temp->next;
            j = j->next;
        }
        if(carry){
            temp->next = new Node(carry);
            carry = 0;
            temp = temp->next;
        }
        return dummy->next;
    }
};

// TC and SC same as Optimal
