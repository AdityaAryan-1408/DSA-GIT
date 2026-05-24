/*

Problem Name   : Exchange Seats
Platform       : LeetCode
Topic          : Database
Problem Link   : https://leetcode.com/problems/exchange-seats/submissions/2011500080/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-24

*/

SELECT
    CASE
        WHEN id = (SELECT MAX(id) FROM Seat) AND MOD(id, 2) = 1
        THEN id
        WHEN
            MOD(id, 2) = 1
            THEN id + 1
        ELSE
            id - 1
    END AS id, student
FROM Seat
ORDER BY id
