/*

Problem Name   : Copy List with Random Pointer
Platform       : LeetCode
Topic          : Hash Table, Linked List
Problem Link   : https://leetcode.com/problems/copy-list-with-random-pointer/submissions/2024059136/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-06
Approach       : No Map
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return nullptr;

        Node* curr = head;
        while (curr) {
            Node* currNext = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = currNext;

            curr = currNext;
        }

        curr = head;
        while (curr && curr->next) {
            if (!curr->random) {
                curr->next->random = nullptr;
            } else {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        Node* newHead = head->next;
        Node* newCurr = newHead;
        curr = head;
        while (curr && newCurr) {
            curr->next = curr->next == nullptr ? nullptr : curr->next->next;
            newCurr->next =
                newCurr->next == nullptr ? nullptr : newCurr->next->next;
            curr = curr->next;
            newCurr = newCurr->next;
        }
        return newHead;
    }
};
