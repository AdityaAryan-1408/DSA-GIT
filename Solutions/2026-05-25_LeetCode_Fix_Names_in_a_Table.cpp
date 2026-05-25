/*

Problem Name   : Fix Names in a Table
Platform       : LeetCode
Topic          : Database
Problem Link   : https://leetcode.com/problems/fix-names-in-a-table/submissions/2012353625/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-05-25

*/

SELECT user_id,
    CONCAT(UPPER(LEFT(name, 1)), LOWER(RIGHT(name, LENGTH(name) - 1))) AS name
FROM Users
ORDER BY user_id
