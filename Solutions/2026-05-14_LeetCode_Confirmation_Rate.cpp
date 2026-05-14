/*

Problem Name   : Confirmation Rate
Platform       : LeetCode
Topic          : Database
Problem Link   : https://leetcode.com/problems/confirmation-rate/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-14

*/

SELECT s.user_id, IFNULL(ROUND(SUM(action = 'confirmed')/COUNT(*), 2), 0.00) AS confirmation_rate
FROM Signups s
LEFT JOIN Confirmations c
ON s.user_id = c.user_id
GROUP BY s.user_id
