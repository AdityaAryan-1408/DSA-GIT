/*

Problem Name   : Product Sales Analysis I
Platform       : LeetCode
Topic          : Database, SQL50
Problem Link   : https://leetcode.com/problems/product-sales-analysis-i/submissions/2001270823/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-05-12
Approach       : Approach 3

*/

SELECT p.product_name, s.year, s.price
FROM Sales s, Product p
WHERE s.product_id = p.product_id;
