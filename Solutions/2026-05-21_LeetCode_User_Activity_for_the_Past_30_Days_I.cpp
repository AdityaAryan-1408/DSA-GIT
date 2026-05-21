/*

Problem Name   : User Activity for the Past 30 Days I
Platform       : LeetCode
Topic          : Database
Problem Link   : https://leetcode.com/problems/user-activity-for-the-past-30-days-i/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-05-21

*/

SELECT activity_date AS day,
COUNT(DISTINCT user_id) AS active_users
FROM Activity
WHERE
activity_date>= '2019-06-28' AND activity_date <= '2019-07-27'
GROUP BY activity_date
