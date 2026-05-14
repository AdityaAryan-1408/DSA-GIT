/*

Problem Name   : Managers with at Least 5 Direct Reports
Platform       : LeetCode
Topic          : Database
Problem Link   : https://leetcode.com/problems/managers-with-at-least-5-direct-reports/submissions/2002817243/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-14

*/

SELECT e1.name
FROM Employee e1
INNER JOIN Employee e2
ON e1.id = e2.managerId
GROUP BY e2.managerID
HAVING COUNT(e2.managerId) >= 5;
