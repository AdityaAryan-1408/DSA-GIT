/*

Problem Name   : Not Boring Movies
Platform       : LeetCode
Topic          : Database, SQL50
Problem Link   : https://leetcode.com/problems/not-boring-movies/submissions/2002831133/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-05-14

*/

SELECT id, movie, description, rating
FROM Cinema
WHERE (id % 2 = 1) AND description != 'boring'
ORDER BY rating DESC
