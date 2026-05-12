/*

Problem Name   : Customer Who Visited but Did Not Make Any Transactions
Platform       : LeetCode
Topic          : Database
Problem Link   : https://leetcode.com/problems/customer-who-visited-but-did-not-make-any-transactions/submissions/2001281435/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-05-12
Approach       : Approach 3

*/

SELECT customer_id, COUNT(*) AS count_no_trans
FROM Visits
WHERE visit_id NOT IN (
    SELECT visit_id
    FROM Transactions
)
GROUP BY customer_id;
