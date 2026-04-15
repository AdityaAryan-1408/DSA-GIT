/*

Problem Name   : Word Search
Platform       : LeetCode
Topic          : Array, String, Backtracking, Depth-First Search, Matrix
Problem Link   : https://leetcode.com/problems/word-search/submissions/1979514843/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-15
Time           : O(m*n*3^L)
Space          : O(L)

*/

class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool find(vector<vector<char>>& board, int i, int j, int ind,
              string& word) {
        int m = board.size();
        int n = board[0].size();

        if (ind == word.size())
            return true;

        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '$')
            return false;

        if (board[i][j] != word[ind])
            return false;

        char temp = board[i][j];
        board[i][j] = '$';
        for (auto dir : directions) {
            int newI = i + dir[0];
            int newJ = j + dir[1];

            if (find(board, newI, newJ, ind + 1, word))
                return true;
        }

        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        if (word.length() > m * n) {
            return false;
        }

        unordered_map<char, int> wordCount;
        for (char c : word)
            wordCount[c]++;

        unordered_map<char, int> boardCount;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                boardCount[board[i][j]]++;
        }

        for (auto const& [key, val] : wordCount) {
            if (boardCount[key] < val) {
                return false;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && find(board, i, j, 0, word))
                    return true;
            }
        }
        return false;
    }
};
