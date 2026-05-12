/*

Problem Name   : Customer Who Visited but Did Not Make Any Transactions
Platform       : LeetCode
Topic          : Database
Problem Link   : https://leetcode.com/problems/customer-who-visited-but-did-not-make-any-transactions/submissions/2001281435/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-05-12
Approach       : Approach 2

*/

SELECT customer_id, COUNT(*) AS count_no_trans
FROM Visits v
WHERE NOT EXISTS (
    SELECT 1
    FROM Transactions t
    WHERE t.visit_id = v.visit_id
)
GROUP BY customer_id;
