/*

Problem Name   : Copy List with Random Pointer
Platform       : LeetCode
Topic          : Hash Table, Linked List
Problem Link   : https://leetcode.com/problems/copy-list-with-random-pointer/submissions/2024059136/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-06-06
Approach       : Map
Time           : O(N)
Space          : O(N)

*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        unordered_map<Node*, Node*> mp;
        Node* curr = head;
        Node* prev = nullptr;
        Node* newHead = nullptr;

        while (curr) {
            Node* temp = new Node(curr->val);
            mp[curr] = temp;
            if (!newHead) {
                newHead = temp;
                prev = newHead;
            } else {
                prev->next = temp;
                prev = temp;
            }
            curr = curr->next;
        }

        curr = head;
        Node* newCurr = newHead;
        while (curr) {
            if (!curr->random) {
                newCurr->random = nullptr;
            } else {
                Node* randomOriginal = curr->random;
                Node* deepRandom = mp[randomOriginal];
                newCurr->random = deepRandom;
                // newCurr->random = mp[curr->random];
            }
            curr = curr->next;
            newCurr = newCurr->next;
        }
        return newHead;
    }
};
