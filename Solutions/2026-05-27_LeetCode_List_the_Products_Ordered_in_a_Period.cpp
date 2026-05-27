/*

Problem Name   : List the Products Ordered in a Period
Platform       : LeetCode
Topic          : Database, SQL50
Problem Link   : https://leetcode.com/problems/list-the-products-ordered-in-a-period/submissions/2014775669/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-05-27

*/

SELECT product_name, SUM(unit) AS unit
FROM Products INNER JOIN Orders USING(product_id)
WHERE MONTH(order_date) = '2' AND YEAR(order_date) = '2020'
GROUP BY product_name
HAVING unit >= 100
