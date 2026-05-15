/*

Problem Name   : Percentage of Users Attended a Contest
Platform       : LeetCode
Topic          : Database
Problem Link   : https://leetcode.com/problems/percentage-of-users-attended-a-contest/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-05-15

*/

SELECT contest_id, ROUND(COUNT(distinct user_id) * 100 / (
    SELECT COUNT(user_id) FROM Users
), 2) AS percentage
FROM Register
GROUP BY contest_id
ORDER BY percentage DESC, contest_id
