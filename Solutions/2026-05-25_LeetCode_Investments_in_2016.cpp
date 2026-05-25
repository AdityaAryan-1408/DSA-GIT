/*

Problem Name   : Investments in 2016
Platform       : LeetCode
Topic          : Database, SQL50
Problem Link   : https://leetcode.com/problems/investments-in-2016/submissions/2012290803/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-25

*/

SELECT ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM Insurance
WHERE tiv_2015 IN (
    SELECT tiv_2015
    FROM Insurance
    GROUP BY tiv_2015
    HAVING COUNT(*) > 1
) AND (lat, lon) IN (
    SELECT lat, lon
    FROM Insurance
    GROUP BY lat, lon
    HAVING COUNT(*) = 1
)
