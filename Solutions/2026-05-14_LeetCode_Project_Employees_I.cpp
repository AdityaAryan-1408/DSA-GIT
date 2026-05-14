/*

Problem Name   : Project Employees I
Platform       : LeetCode
Topic          : Database
Problem Link   : https://leetcode.com/problems/project-employees-i/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-05-14

*/

SELECT p.project_id, ROUND(AVG(e.experience_years), 2) AS average_years
FROM Project p
LEFT JOIN Employee e
ON p.employee_id = e.employee_id
GROUP BY p.project_id
