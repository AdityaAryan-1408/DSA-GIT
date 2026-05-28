/*

Problem Name   : Longest Common Suffix Queries
Platform       : LeetCode
Topic          : Array, String, Trie
Problem Link   : https://leetcode.com/problems/longest-common-suffix-queries/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-05-28
Approach       : Alternative - No MLE
Time           : O(S + Q)
Space          : O(Sigma * S)

*/

class Solution {
public:
    class TrieNode {
    public:
        int index;
        int children[26]; // int indices instead of pointers (4B vs 8B each)
        TrieNode(int i) {
            index = i;
            fill(children, children + 26, -1); // -1 means null
        }
    };

    vector<TrieNode> pool;

    void insert(int root, int i, vector<string>& wordsContainer) {
        string& word = wordsContainer[i];
        int n = word.size();
        for (int j = n - 1; j >= 0; j--) {
            int ind = word[j] - 'a';

            if (pool[root].children[ind] == -1) {
                pool[root].children[ind] = pool.size();
                pool.emplace_back(i);
            }

            root = pool[root].children[ind];

            if (wordsContainer[pool[root].index].size() > (size_t)n) {
                pool[root].index = i;
            }
        }
    }

    int search(int root, string& word) {
        int resInd = pool[root].index;
        int n = word.size();

        for (int i = n - 1; i >= 0; i--) {
            int ind = word[i] - 'a';
            if (pool[root].children[ind] == -1) {
                return resInd;
            }

            root = pool[root].children[ind];
            resInd = pool[root].index;
        }
        return resInd;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {
        int n = wordsContainer.size();
        int m = wordsQuery.size();

        int totalChars = 0;
        for (auto& w : wordsContainer)
            totalChars += w.size();
        pool.reserve(totalChars + 1);
        pool.emplace_back(0); // root node

        for (int i = 0; i < n; i++) {
            if (wordsContainer[pool[0].index].size() >
                wordsContainer[i].size()) {
                pool[0].index = i;
            }
            insert(0, i, wordsContainer);
        }

        vector<int> result(m);
        for (int i = 0; i < m; i++) {
            result[i] = search(0, wordsQuery[i]);
        }

        return result;
    }
};
