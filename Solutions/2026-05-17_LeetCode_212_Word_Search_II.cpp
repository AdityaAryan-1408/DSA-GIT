/*

Problem Name   : 212. Word Search II
Platform       : LeetCode
Topic          : Array, String, Backtracking, Trie, Matrix
Problem Link   : https://leetcode.com/problems/word-search-ii/submissions/2005403710/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-05-17
Time           : O(S+mn⋅3^L)
Space          : O(S+L)

*/

class TrieNode {
public:
    bool isEnd;
    string word;
    vector<TrieNode*> children;

    TrieNode() {
        isEnd = false;
        word = "";
        children.resize(26, nullptr);
    }
};

class Solution {
public:
    vector<string> result;
    int r, c;
    vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    void insert(TrieNode* root, string str) {
        TrieNode* crawler = root;

        for (char ch : str) {
            int ind = ch - 'a';

            if (crawler->children[ind] == nullptr) {
                crawler->children[ind] = new TrieNode();
            }

            crawler = crawler->children[ind];
        }

        crawler->isEnd = true;
        crawler->word = str;
    }

    void DFS(vector<vector<char>>& board, int i, int j, TrieNode* root) {

        if (i < 0 || i >= r || j < 0 || j >= c || board[i][j] == '$') {
            return;
        }
        char ch = board[i][j];

        if (root->children[ch - 'a'] == nullptr)
            return;
        root = root->children[ch - 'a'];

        if (root->isEnd) {
            result.push_back(root->word);
            root->isEnd = false;
        }

        board[i][j] = '$';

        for (auto dir : directions) {
            int newI = i + dir.first;
            int newJ = j + dir.second;

            DFS(board, newI, newJ, root);
        }

        board[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        r = board.size();
        c = board[0].size();

        TrieNode* root = new TrieNode();

        for (string word : words) {
            insert(root, word);
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {

                if (root->children[board[i][j] - 'a'] != nullptr) {
                    DFS(board, i, j, root);
                }
            }
        }

        return result;
    }
};
