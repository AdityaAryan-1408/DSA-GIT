/*

Problem Name   : Customers Who Bought All Products
Platform       : LeetCode
Topic          : Database
Problem Link   : https://leetcode.com/problems/customers-who-bought-all-products/submissions/2009710005/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-22

*/

SELECT customer_id
FROM Customer
GROUP BY customer_id
HAVING COUNT(DISTINCT product_key) = (
    SELECT COUNT(product_key)
    FROM Product
)
