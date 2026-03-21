/*

Problem Name   : Valid Sudoku
Platform       : LeetCode
Topic          : Array, Hash Table, Matrix
Problem Link   : https://leetcode.com/problems/valid-sudoku/submissions/1954927568/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-21
Approach       : Alternative
Time           : O(1)
Space          : O(1)

*/

class Solution {
public:
    bool validBox(vector<vector<char>>& board, int startingRow, int endingRow,
                  int startingCol, int endingCol) {
        unordered_set<char> seen;
        for (int i = startingRow; i <= endingRow; i++) {
            for (int j = startingCol; j <= endingCol; j++) {
                if (board[i][j] != '.') {
                    if (seen.find(board[i][j]) != seen.end()) {
                        return false;
                    }
                    seen.insert(board[i][j]);
                }
            }
        }
        return true;
    }

    
    bool isValidSudoku(vector<vector<char>>& board) {
        // Rows
        for (int row = 0; row < 9; row++) {
            unordered_set<char> seen;
            for (int col = 0; col < 9; col++) {
                if (board[row][col] != '.') {
                    if (seen.find(board[row][col]) != seen.end()) {
                        return false;
                    }
                    seen.insert(board[row][col]);
                }
            }
        }

        // Columns
        for (int col = 0; col < 9; col++) {
            unordered_set<char> seen;
            for (int row = 0; row < 9; row++) {
                if (board[row][col] != '.') {
                    if (seen.find(board[row][col]) != seen.end()) {
                        return false;
                    }
                    seen.insert(board[row][col]);
                }
            }
        }

        // Box
        for (int startingRow = 0; startingRow < 9; startingRow += 3) {
            int endingRow = startingRow + 2;
            for (int startingCol = 0; startingCol < 9; startingCol += 3) {
                int endingCol = startingCol + 2;
                if (validBox(board, startingRow, endingRow, startingCol,
                             endingCol) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};
