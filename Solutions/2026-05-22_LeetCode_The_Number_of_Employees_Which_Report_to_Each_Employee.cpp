/*

Problem Name   : The Number of Employees Which Report to Each Employee
Platform       : LeetCode
Topic          : Database
Problem Link   : https://leetcode.com/problems/the-number-of-employees-which-report-to-each-employee/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-05-22

*/

SELECT 
    E1.employee_id,
    E1.name,
    COUNT(E2.employee_id) AS reports_count,
    ROUND(AVG(E2.age)) AS average_age
FROM Employees E1 INNER JOIN Employees E2
ON E1.employee_id = E2.reports_to
GROUP BY E1.employee_id, E1.name -- Group by has the same things as select
ORDER BY employee_id
