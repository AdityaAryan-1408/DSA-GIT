/*

Problem Name   : Count Salary Categories
Platform       : LeetCode
Topic          : Database
Problem Link   : https://leetcode.com/problems/count-salary-categories/submissions/2010556051/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-23

*/

SELECT "Low Salary" AS category,COUNT(income) AS accounts_count
FROM Accounts
WHERE income < 20000
UNION
SELECT "Average Salary" AS category,COUNT(income) AS accounts_count
FROM Accounts
WHERE income >= 20000 AND income <= 50000
UNION
SELECT "High Salary" AS category,COUNT(income) AS accounts_count
FROM Accounts
WHERE income > 50000
