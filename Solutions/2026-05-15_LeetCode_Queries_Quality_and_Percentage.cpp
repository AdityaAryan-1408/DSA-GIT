/*

Problem Name   : Queries Quality and Percentage
Platform       : LeetCode
Topic          : Database
Problem Link   : https://leetcode.com/problems/queries-quality-and-percentage/submissions/2003608065/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-05-15

*/

SELECT query_name, 
ROUND(AVG(rating / position), 2) AS Quality, 
ROUND(AVG(IF(rating < 3, 1 , 0)) * 100, 2) AS poor_query_percentage
FROM Queries
GROUP BY query_name
