/*

Problem Name   : Biggest Single Number
Platform       : LeetCode
Topic          : Database
Problem Link   : https://leetcode.com/problems/biggest-single-number/submissions/2009688753/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-05-22

*/

SELECT MAX(num) AS num
FROM MyNumbers
WHERE num IN (
    SELECT num
    FROM MyNumbers
    GROUP BY num
    HAVING COUNT(*) = 1
)
