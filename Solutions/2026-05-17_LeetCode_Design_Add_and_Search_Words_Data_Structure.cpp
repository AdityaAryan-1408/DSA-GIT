/*

Problem Name   : Design Add and Search Words Data Structure
Platform       : LeetCode
Topic          : String, Depth-First Search, Design, Trie
Problem Link   : https://leetcode.com/problems/design-add-and-search-words-data-structure/submissions/2005363971/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-17
Time           : O(N)
Space          : O(N)

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
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        TrieNode* crawler = root;

        for (int i = 0; i < word.size(); i++) {
            int ind = word[i] - 'a';
            if (crawler->children[ind] == nullptr)
                crawler->children[ind] = new TrieNode();

            crawler = crawler->children[ind];
        }
        crawler->isEnd = true;
    }

    bool searchUtil(TrieNode* root, string word) {
        TrieNode* crawler = root;

        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];

            if (ch == '.') {
                for (int j = 0; j < 26; j++) {
                    if (crawler->children[j] != nullptr) {
                        if (searchUtil(crawler->children[j],
                                       word.substr(i + 1))) {
                            return true;
                        }
                    }
                }
                return false;
            }
            if (crawler->children[ch - 'a'] == nullptr)
                return false;

            crawler = crawler->children[ch - 'a'];
        }
        return (crawler->isEnd);
    }
    bool search(string word) { return searchUtil(root, word); }
};
