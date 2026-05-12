/*

Problem Name   : Customer Who Visited but Did Not Make Any Transactions
Platform       : LeetCode
Topic          : Database
Problem Link   : https://leetcode.com/problems/customer-who-visited-but-did-not-make-any-transactions/submissions/2001281435/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-05-12
Approach       : Approach 4

*/

SELECT v.customer_id, COUNT(*) AS count_no_trans
FROM Visits v
LEFT JOIN Transactions t
ON v.visit_id = t.visit_id
GROUP BY v.customer_id, v.visit_id
HAVING COUNT(t.transaction_id) = 0;
