/*

Problem Name   : Patients With a Condition
Platform       : LeetCode
Topic          : Database, SQL50
Problem Link   : https://leetcode.com/problems/patients-with-a-condition/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-05-25

*/

SELECT *
FROM Patients
WHERE conditions LIKE ('DIAB1%') OR conditions LIKE('% DIAB1%')
