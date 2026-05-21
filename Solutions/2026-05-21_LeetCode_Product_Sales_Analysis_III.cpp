/*

Problem Name   : Product Sales Analysis III
Platform       : LeetCode
Topic          : Database
Problem Link   : https://leetcode.com/problems/product-sales-analysis-iii/submissions/2008923565/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-21

*/

SELECT product_id, year AS first_year,
quantity, price
FROM Sales
WHERE (product_id, year) IN (
    SELECT product_id, MIN(year) AS f_year
    FROM SALES
    GROUP BY product_id
)
