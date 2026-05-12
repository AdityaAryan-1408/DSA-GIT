/*

Problem Name   : Customer Who Visited but Did Not Make Any Transactions
Platform       : LeetCode
Topic          : Database
Problem Link   : https://leetcode.com/problems/customer-who-visited-but-did-not-make-any-transactions/submissions/2001281435/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-05-12
Approach       : Approach 1

*/

SELECT customer_id, COUNT(*) as count_no_trans
FROM Visits as v
LEFT JOIN
Transactions as t
ON
v.visit_id = t.visit_id
WHERE 
t.transaction_id IS NULL
GROUP BY customer_id
