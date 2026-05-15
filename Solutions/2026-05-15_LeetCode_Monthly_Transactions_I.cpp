/*

Problem Name   : Monthly Transactions I
Platform       : LeetCode
Topic          : Database
Problem Link   : https://leetcode.com/problems/monthly-transactions-i/submissions/2003627723/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-15

*/

SELECT
    DATE_FORMAT(trans_date, '%Y-%m') AS month,
    country,
    COUNT(id) AS trans_count,
    SUM(state = 'approved') AS approved_count,
    SUM(amount) AS trans_total_amount,
    SUM(IF(state = 'approved', amount, 0)) AS approved_total_amount 
FROM Transactions
GROUP BY month, country
