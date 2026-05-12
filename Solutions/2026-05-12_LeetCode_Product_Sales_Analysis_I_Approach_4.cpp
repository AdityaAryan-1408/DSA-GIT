/*

Problem Name   : Product Sales Analysis I
Platform       : LeetCode
Topic          : Database, SQL50
Problem Link   : https://leetcode.com/problems/product-sales-analysis-i/submissions/2001270823/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-05-12
Approach       : Approach 4

*/

SELECT product_name, year, price
FROM Sales
JOIN Product
USING(product_id);
