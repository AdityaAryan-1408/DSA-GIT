/*

Problem Name   : Average Time of Process per Machine
Platform       : LeetCode
Topic          : Database
Problem Link   : https://leetcode.com/problems/average-time-of-process-per-machine/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-05-12
Approach       : Approach 1

*/

SELECT 
    a1.machine_id,
    ROUND(AVG(a2.timestamp - a1.timestamp), 3) AS processing_time
FROM Activity AS a1,
     Activity AS a2
WHERE a1.activity_type = 'start'
AND a2.activity_type = 'end'
AND a1.process_id = a2.process_id
AND a1.machine_id = a2.machine_id
GROUP BY a1.machine_id;

#Mysql
