/*

Problem Name   : Department Top Three Salaries
Platform       : LeetCode
Topic          : Database, SQL50
Problem Link   : https://leetcode.com/problems/department-top-three-salaries/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-05-25

*/

SELECT 
    d.name AS Department,
    e1.name AS Employee,
    e1.salary AS Salary

FROM Employee e1 INNER JOIN Department d
ON e1.departmentID = d.id
WHERE 3 > (
    SELECT COUNT(DISTINCT (Salary))
    FROM Employee e2
    WHERE e2.Salary > e1.Salary AND 
    e1.DepartmentID = e2.DepartmentID
)
