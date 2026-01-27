/*

Problem Name   : Word Search
Platform       : GeeksForGeeks
Topic          : Graph
Problem Link   : https://www.geeksforgeeks.org/problems/word-search/1
Type           : POTD
Difficulty     : Medium
Date Solved    : 2026-01-27

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int n, m;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    bool dfs(int i, int j, int idx, vector<vector<char>>& mat, string& word) {
        if (idx == word.size()) return true;

        if (i < 0 || i >= n || j < 0 || j >= m || mat[i][j] != word[idx])
            return false;

        char temp = mat[i][j];
        mat[i][j] = '#';  // mark visited

        for (int d = 0; d < 4; d++) {
            if (dfs(i + dx[d], j + dy[d], idx + 1, mat, word)) return true;
        }

        mat[i][j] = temp;  // backtrack
        return false;
    }

    bool isWordExist(vector<vector<char>>& mat, string& word) {
        n = mat.size();
        m = mat[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == word[0]) {
                    if (dfs(i, j, 0, mat, word)) return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution s;

    return 0;
}