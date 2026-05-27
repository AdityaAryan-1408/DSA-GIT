/*

Problem Name   : Delete Duplicate Emails
Platform       : LeetCode
Topic          : Database, SQL50
Problem Link   : https://leetcode.com/problems/delete-duplicate-emails/submissions/2014742625/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-05-27

*/

DELETE p1
FROM Person p1 INNER JOIN Person p2
WHERE p1.email = p2.email AND
p1.id > p2.id
