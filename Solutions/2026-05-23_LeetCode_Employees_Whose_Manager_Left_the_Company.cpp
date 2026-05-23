/*

Problem Name   : Employees Whose Manager Left the Company
Platform       : LeetCode
Topic          : Database
Problem Link   : https://leetcode.com/problems/employees-whose-manager-left-the-company/submissions/2010560356/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-05-23

*/

SELECT employee_id
FROM Employees
WHERE salary < 30000 AND
    manager_id NOT IN (
        SELECT employee_id
        FROM Employees
    )
ORDER BY employee_id
