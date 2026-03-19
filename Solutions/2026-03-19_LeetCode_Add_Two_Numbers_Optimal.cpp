/*

Problem Name   : Add Two Numbers
Platform       : LeetCode
Topic          : Linked List, Math, Recursion
Problem Link   : https://leetcode.com/problems/add-two-numbers/submissions/1953205202/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-19
Approach       : Optimal
Time           : O(N + M)
Space          : O(max(N, M))

*/

using Node = ListNode;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        Node* dummy = new Node();
        Node* temp = dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = 0;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            sum += carry;
            carry = sum / 10;
            temp->next = new Node(sum % 10);
            temp = temp->next;
        }
        return dummy->next;
    }
};
