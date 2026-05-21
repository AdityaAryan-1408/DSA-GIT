/*

Problem Name   : Number of Unique Subjects Taught by Each Teacher
Platform       : LeetCode
Topic          : Database, SQL50
Problem Link   : https://leetcode.com/problems/number-of-unique-subjects-taught-by-each-teacher/submissions/2008844529/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-05-21

*/

SELECT teacher_id, COUNT(DISTINCT subject_id) AS cnt
FROM Teacher
GROUP BY teacher_id
