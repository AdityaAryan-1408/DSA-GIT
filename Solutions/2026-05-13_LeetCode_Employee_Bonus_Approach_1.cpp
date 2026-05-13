/*

Problem Name   : Employee Bonus
Platform       : LeetCode
Topic          : Database, SQL50
Problem Link   : https://leetcode.com/problems/employee-bonus/submissions/2001922534/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-05-13
Approach       : Approach 1

*/

SELECT e.name, b.bonus
FROM Employee as e
LEFT JOIN
Bonus as b
ON
e.empid = b.empid
WHERE
b.bonus < 1000 OR b.bonus IS NULL
