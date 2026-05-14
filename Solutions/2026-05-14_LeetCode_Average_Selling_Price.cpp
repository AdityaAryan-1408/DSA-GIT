/*

Problem Name   : Average Selling Price
Platform       : LeetCode
Topic          : Database
Problem Link   : https://leetcode.com/problems/average-selling-price/submissions/2002898889/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-05-14

*/

SELECT p.product_id, IFNULL(ROUND(SUM(p.price * u.units)/SUM(u.units) , 2), 0) AS average_price
FROM Prices p
LEFT JOIN UnitsSold u
ON p.product_id = u.product_id
AND u.purchase_date >= p.start_date
AND u.purchase_date <= p.end_date
GROUP BY p.product_id
