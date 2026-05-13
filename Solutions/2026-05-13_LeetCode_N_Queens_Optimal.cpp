/*

Problem Name   : N-Queens
Platform       : LeetCode
Topic          : Array, Backtracking
Problem Link   : https://leetcode.com/problems/n-queens/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-05-13
Approach       : Optimal
Time           : O(N!)
Space          : O(N)

*/

class Solution {
public:
    vector<vector<string>> res;
    unordered_set<int> cols, diag, antidiag;

    int N;

    void solve(vector<string>& board, int row) {
        if (row >= N) {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < N; col++) {
            int diagonalConst = row + col;
            int antiDiagonalConst = row - col;
            if (cols.find(col) != cols.end() ||
                diag.find(diagonalConst) != diag.end() ||
                antidiag.find(antiDiagonalConst) != antidiag.end()) {
                continue;
            }

            cols.insert(col);
            diag.insert(diagonalConst);
            antidiag.insert(antiDiagonalConst);
            board[row][col] = 'Q';
            solve(board, row + 1);
            cols.erase(col);
            diag.erase(diagonalConst);
            antidiag.erase(antiDiagonalConst);
            board[row][col] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        N = n;
        solve(board, 0);

        return res;
    }
};

// TC = O(N!)
// SC = O(N)
