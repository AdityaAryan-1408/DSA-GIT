/*

Problem Name   : Triangle Judgement
Platform       : LeetCode
Topic          : Database, SQL50
Problem Link   : https://leetcode.com/problems/triangle-judgement/submissions/2009734366/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-05-22

*/

SELECT *, 
    IF(x + y > z AND y + z > x AND z + x > y, 'Yes', 'No') AS triangle
FROM Triangle
