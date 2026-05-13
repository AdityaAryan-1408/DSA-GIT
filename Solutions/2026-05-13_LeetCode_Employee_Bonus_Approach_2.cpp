/*

Problem Name   : Employee Bonus
Platform       : LeetCode
Topic          : Database, SQL50
Problem Link   : https://leetcode.com/problems/employee-bonus/submissions/2001922534/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-05-13
Approach       : Approach 2

*/

SELECT e.name, b.bonus
FROM Employee e
LEFT JOIN Bonus b ON e.empid = b.empid
WHERE e.empid NOT IN (
    SELECT empid 
    FROM Bonus 
    WHERE bonus >= 1000
);
