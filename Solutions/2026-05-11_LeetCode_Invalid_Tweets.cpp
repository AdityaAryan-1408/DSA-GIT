/*

Problem Name   : Invalid Tweets
Platform       : LeetCode
Topic          : Database
Problem Link   : https://leetcode.com/problems/invalid-tweets/submissions/2000763363/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-05-11

*/

SELECT tweet_id
FROM Tweets
WHERE LENGTH(content) > 15;
