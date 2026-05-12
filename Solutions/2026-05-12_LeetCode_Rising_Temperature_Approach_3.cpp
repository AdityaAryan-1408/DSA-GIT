/*

Problem Name   : Rising Temperature
Platform       : LeetCode
Topic          : Database
Problem Link   : https://leetcode.com/problems/rising-temperature/submissions/2001289127/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-05-12
Approach       : Approach 3

*/

SELECT today.id
FROM Weather today, Weather yesterday
WHERE DATEDIFF(today.recordDate, yesterday.recordDate) = 1
AND today.temperature > yesterday.temperature;
