/*

Problem Name   : Add Two Numbers
Platform       : LeetCode
Topic          : Linked List, Math, Recursion
Problem Link   : https://leetcode.com/problems/add-two-numbers/submissions/1953205202/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-19
Approach       : In Place
Time           : O(N + M)
Space          : O(max(N, M))

*/

using Node = ListNode;
class Solution {
public:
    int listLen(Node* head){
        int len = 0;
        Node* temp = head;
        while(temp){
            len++;
            temp = temp->next;
        }
        return len;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(listLen(l1) < listLen(l2)) swap(l1, l2);

        Node *i = l1, *j = l2;
        int carry = 0;
        Node* prev = nullptr;
        while(i && j){
            int sum = i->val + j->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            i->val = sum;
            prev = i;
            i = i->next;
            j = j->next;
        }
        while(i){
            int sum = i->val + carry;
            carry = sum/10;
            sum = sum%10;
            i->val = sum;
            prev = i;
            i = i->next;
        }
        if(carry){
            prev->next = new Node(carry);
        }
        return l1;
    }
};

// TC = O(N + M)
// SC = O(1)
