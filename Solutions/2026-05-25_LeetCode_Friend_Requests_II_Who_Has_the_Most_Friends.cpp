/*

Problem Name   : Friend Requests II: Who Has the Most Friends
Platform       : LeetCode
Topic          : Database, SQL50
Problem Link   : https://leetcode.com/problems/friend-requests-ii-who-has-the-most-friends/submissions/2012279518/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-25

*/

SELECT id, COUNT(*) AS NUM
FROM (
    SELECT requester_id AS id
    FROM RequestAccepted

    UNION ALL 

    SELECT accepter_id AS id
    FROM RequestAccepted
) AS fc
GROUP BY id
ORDER BY num DESC
LIMIT 1
