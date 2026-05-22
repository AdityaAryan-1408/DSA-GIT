/*

Problem Name   : Primary Department for Each Employee
Platform       : LeetCode
Topic          : Database
Problem Link   : https://leetcode.com/problems/primary-department-for-each-employee/submissions/2009728042/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-05-22

*/

SELECT DISTINCT employee_id, department_id
FROM Employee
WHERE employee_id IN (
    SELECT employee_id -- select here has the same thing as whats after where.
    FROM Employee
    GROUP BY employee_id
    HAVING COUNT(*) = 1
) OR primary_flag = 'Y'
