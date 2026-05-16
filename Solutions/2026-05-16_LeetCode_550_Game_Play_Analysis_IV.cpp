/*

Problem Name   : 550. Game Play Analysis IV
Platform       : LeetCode
Topic          : Database
Problem Link   : https://leetcode.com/problems/game-play-analysis-iv/submissions/2004487900/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-16

*/

SELECT ROUND(COUNT(DISTINCT player_id) / (SELECT COUNT(DISTINCT player_id) FROM Activity), 2) AS fraction
FROM Activity
WHERE (player_id, DATE_SUB(event_date, INTERVAL 1 DAY)) IN (
    SELECT player_id, MIN(event_date) AS first_login
    FROM Activity
    GROUP BY player_id
)
