/*

Problem Name   : Linked List Cycle
Platform       : LeetCode
Topic          : Hash Table, Linked List, Two Pointers
Problem Link   : https://leetcode.com/problems/linked-list-cycle/submissions/1952974353/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-03-19
Time           : O(N)
Space          : O(1)

*/

using Node = ListNode;
class Solution {
public:
    bool hasCycle(ListNode *head) {
        Node* slow = head;
        Node * fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};
