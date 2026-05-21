/*

Problem Name   : Find Followers Count
Platform       : LeetCode
Topic          : Database
Problem Link   : https://leetcode.com/problems/find-followers-count/submissions/2008935531/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-05-21
Approach       : Optimal

*/

SELECT user_id, COUNT(follower_id) AS followers_count
FROM Followers
GROUP BY user_id
ORDER BY user_id
