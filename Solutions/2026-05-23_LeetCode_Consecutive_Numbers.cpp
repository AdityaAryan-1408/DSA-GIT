/*

Problem Name   : Consecutive Numbers
Platform       : LeetCode
Topic          : Database, SQL50
Problem Link   : https://leetcode.com/problems/consecutive-numbers/submissions/2010423926/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-23

*/

SELECT DISTINCT l1.num AS ConsecutiveNums
FROM Logs l1, Logs l2, Logs l3
WHERE l1.id = l2.id - 1 AND l2.id = l3.id - 1
AND l1.num = l2.num AND l2.num = l3.num
