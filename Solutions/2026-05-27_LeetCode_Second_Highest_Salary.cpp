/*

Problem Name   : Second Highest Salary
Platform       : LeetCode
Topic          : Database
Problem Link   : https://leetcode.com/problems/second-highest-salary/submissions/2014749379/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-27

*/

SELECT (
    SELECT salary 
    FROM Employee
    ORDER BY Salary DESC
    LIMIT 1 OFFSET 1
)AS SecondHighestSalary
