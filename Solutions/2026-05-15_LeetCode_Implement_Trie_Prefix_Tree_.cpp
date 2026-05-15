/*

Problem Name   : Implement Trie (Prefix Tree)
Platform       : LeetCode
Topic          : Hash Table, String, Design, Trie
Problem Link   : https://leetcode.com/problems/implement-trie-prefix-tree/submissions/2003755171/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-15
Time           : O(L) for all 3 functions
Space          : O(N*L)

*/

class TrieNode {
public:
    bool isEnd;
    vector<TrieNode*> children;
    TrieNode() {
        isEnd = false;
        children.resize(26, nullptr);
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* crawler = root;

        for (int i = 0; i < word.size(); i++) {
            int ind = word[i] - 'a';
            if (crawler->children[ind] == nullptr)
                crawler->children[ind] = new TrieNode();

            crawler = crawler->children[ind];
        }
        crawler->isEnd = true;
    }

    bool search(string word) {
        TrieNode* crawler = root;

        for (int i = 0; i < word.size(); i++) {
            int ind = word[i] - 'a';
            if (crawler->children[ind] == nullptr)
                return false;

            crawler = crawler->children[ind];
        }
        return crawler->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* crawler = root;

        for (int i = 0; i < prefix.size(); i++) {
            int ind = prefix[i] - 'a';
            if (crawler->children[ind] == nullptr)
                return false;

            crawler = crawler->children[ind];
        }
        return true;
    }
};
