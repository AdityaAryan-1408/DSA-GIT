/*

Problem Name   : Find the Length of the Longest Common Prefix
Platform       : LeetCode
Topic          : Array, Hash Table, String, Trie
Problem Link   : https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/submissions/2008814342/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-21
Time           : O(N * M)
Space          : O(N)

*/

class TrieNode {
public:
    bool isEnd;
    vector<TrieNode*> children;
    TrieNode() {
        isEnd = false;
        children.resize(10, nullptr);
    }
};
class Solution {
public:
    TrieNode* root;
    Solution(){
        root = new TrieNode();
    }
    void insert(string num) {
        TrieNode* crawler = root;

        for (int i = 0; i < num.size(); i++) {
            int ind = num[i] - '0';
            if (crawler->children[ind] == nullptr)
                crawler->children[ind] = new TrieNode();

            crawler = crawler->children[ind];
        }
        crawler->isEnd = true;
    }
    int search(string num){
        TrieNode* crawler = root;
        int len = 0;
        for (int i = 0; i < num.size(); i++) {
            int ind = num[i] - '0';
            if (crawler->children[ind] == nullptr)
                break;

            len++;
            crawler = crawler->children[ind];
        }
        return len;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        for(int x : arr1){
            string num = to_string(x);
            insert(num);
        }

        int LCP = 0;
        for(int y : arr2){
            string num = to_string(y);
            LCP = max(LCP, search(num));
        }
        return LCP;
    }
};

// TC = Insertion + Searching = O(N * D) + O(M * D) where D = number of Digits in a numbers. Total = O((N + M) * D). However since arr[i] < 10^8, so D <= 8. So TC ~ O(N * M)

// SC = O(N * D) or O(N)
