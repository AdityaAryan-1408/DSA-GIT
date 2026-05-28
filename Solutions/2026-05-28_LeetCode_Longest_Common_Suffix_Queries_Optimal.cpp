/*

Problem Name   : Longest Common Suffix Queries
Platform       : LeetCode
Topic          : Array, String, Trie
Problem Link   : https://leetcode.com/problems/longest-common-suffix-queries/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-05-28
Approach       : Optimal
Time           : O(S + Q)
Space          : O(Sigma * S)

*/

class Solution {
public:
    class TrieNode {
    public:
        int index;
        TrieNode* children[26];
        TrieNode(int i) {
            index = i;
            for (int j = 0; j < 26; j++) {
                children[j] = nullptr;
            }
        }
    };
    void insert(TrieNode* root, int i, vector<string>& wordsContainer) {
        string& word = wordsContainer[i];
        int n = word.size();
        for (int j = n - 1; j >= 0; j--) {
            int ind = word[j] - 'a';

            if (!root->children[ind]) {
                root->children[ind] = new TrieNode(i);
            }

            root = root->children[ind];

            if (wordsContainer[root->index].size() > n) {
                root->index = i;
            }
        }
    }

    int search(TrieNode* root, string& word) {
        int resInd = root->index;
        int n = word.size();

        for (int i = n - 1; i >= 0; i--) {
            int ind = word[i] - 'a';
            if (!root->children[ind]) {
                return resInd;
            }

            root = root->children[ind];
            resInd = root->index;
        }
        return resInd;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        int n = wordsContainer.size();
        int m = wordsQuery.size();
        vector<int> result(m);
        TrieNode* root = new TrieNode(0);

        for (int i = 0; i < n; i++) {
            int ind = root->index;
            if (wordsContainer[ind].size() > wordsContainer[i].size()) {

                root->index = i;
            }
            insert(root, i, wordsContainer);
        }
        for (int i = 0; i < m; i++) {
            result[i] = search(root, wordsQuery[i]);
        }

        return result;
    }
};
