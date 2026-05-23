/*

Problem Name   : Last Person to Fit in the Bus
Platform       : LeetCode
Topic          : Database
Problem Link   : https://leetcode.com/problems/last-person-to-fit-in-the-bus/submissions/2010469250/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-23

*/

SELECT q1.person_name
FROM Queue q1 INNER JOIN Queue q2
ON q1.turn >= q2.turn
GROUP BY q1.turn
HAVING SUM(q2.weight) <= 1000
ORDER BY SUM(q2.weight) DESC
LIMIT 1
