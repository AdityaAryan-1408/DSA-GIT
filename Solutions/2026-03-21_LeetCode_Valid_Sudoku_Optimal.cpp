/*

Problem Name   : Valid Sudoku
Platform       : LeetCode
Topic          : Array, Hash Table, Matrix
Problem Link   : https://leetcode.com/problems/valid-sudoku/submissions/1954927568/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-21
Approach       : Optimal
Time           : O(1)
Space          : O(1)

*/

class Solution {
   public:
    /*
    In a given box, if the index i, and j are divided by 3, we will get the same value for all the elements in the box. 
    So we can iterate through the board and for each element, we can check if it is already present in the row, 
    column and box. If it is present, then we can return false. If it is not present, then we can insert it in the row, 
    column and box.
    Create a string for each element in the row, column and box. The string will be in the format 
    "rowi" + element, "colj" + element,
    */
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    string row = "row" + to_string(i) + board[i][j];
                    string col = "col" + to_string(j) + board[i][j];
                    string box = "box" + to_string(i / 3) + to_string(j / 3) +
                                 board[i][j];
                    if (seen.find(row) != seen.end() ||
                        seen.find(col) != seen.end() ||
                        seen.find(box) != seen.end()) {
                        return false;
                    }
                    seen.insert(row);
                    seen.insert(col);
                    seen.insert(box);
                }
            }
        }
        return true;
    }
};
