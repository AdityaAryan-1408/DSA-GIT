/*

Problem Name   : Reverse Nodes in k-Group
Platform       : LeetCode
Topic          : Linked List, Recursion
Problem Link   : https://leetcode.com/problems/reverse-nodes-in-k-group/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-03-29
Time           : O(2N)
Space          : O(1)

*/

class Solution {
public:
    ListNode* reverseLL(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while (temp != nullptr) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    ListNode* findkthNode(ListNode* head, int k) {
        k--;
        ListNode* temp = head;
        while (temp != nullptr && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = nullptr;
        while (temp != nullptr) {
            ListNode* kNode = findkthNode(temp, k);
            if (kNode == nullptr) {
                if (prevLast)
                    prevLast->next = temp;
                break;
            }
            ListNode* nextNode = kNode->next;
            kNode->next = nullptr;
            reverseLL(temp);
            if (temp == head) {
                head = kNode;
            } else {
                prevLast->next = kNode;
            }
            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};
