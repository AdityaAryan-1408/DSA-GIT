/*

Problem Name   : Rising Temperature
Platform       : LeetCode
Topic          : Database
Problem Link   : https://leetcode.com/problems/rising-temperature/submissions/2001289127/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-05-12
Approach       : Approach 4

*/

SELECT id
FROM (
    SELECT 
        id,
        temperature,
        recordDate,
        LAG(temperature) OVER (ORDER BY recordDate) AS prev_temp,
        LAG(recordDate) OVER (ORDER BY recordDate) AS prev_date
    FROM Weather
) t
WHERE temperature > prev_temp
AND recordDate - prev_date = 1;
