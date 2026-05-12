/*

Problem Name   : Rising Temperature
Platform       : LeetCode
Topic          : Database
Problem Link   : https://leetcode.com/problems/rising-temperature/submissions/2001289127/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-05-12
Approach       : Approach 1

*/

SELECT today.id from Weather as today
WHERE EXISTS (
    SELECT 1 from Weather as yesterday
    WHERE yesterday.temperature < today.temperature
    AND
    today.recordDate - yesterday.recordDate = 1
)
