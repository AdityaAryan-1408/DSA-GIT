/*

Problem Name   : Classes With at Least 5 Students
Platform       : LeetCode
Topic          : Database
Problem Link   : https://leetcode.com/problems/classes-with-at-least-5-students/submissions/2008932323/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-05-21

*/

SELECT class
FROM Courses
GROUP BY class
HAVING COUNT(class) >= 5
