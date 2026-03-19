/*

Problem Name   : Merge Two Sorted Lists
Platform       : LeetCode
Topic          : Linked List, Recursion
Problem Link   : https://leetcode.com/problems/merge-two-sorted-lists/submissions/1952955523/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-03-19
Approach       : Brute Force
Time           : O(N + M)
Space          : O(1)

*/

using Node = ListNode;
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        Node* result = new Node(0);
        Node* temp = result;
        Node *i = list1, *j = list2;
        while (i && j) {
            int curr;
            if (i->val <= j->val) {
                curr = i->val;
                i = i->next;
            }
            else{
                curr = j->val;
                j = j->next;
            }
            temp->next = new Node(curr);
            temp = temp->next;
        }
        while(i){
            temp->next = new Node(i->val);
            temp = temp->next;
            i = i->next;
        }
        while(j){
            temp->next = new Node(j->val);
            temp = temp->next;
            j = j->next;
        }
        return result->next;
    }
};

// TC = O(N + M)
// SC + O(N + M)
