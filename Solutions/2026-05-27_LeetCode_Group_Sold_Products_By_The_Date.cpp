/*

Problem Name   : Group Sold Products By The Date
Platform       : LeetCode
Topic          : Database, SQL50
Problem Link   : https://leetcode.com/problems/group-sold-products-by-the-date/
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-05-27

*/

SELECT sell_date, COUNT(DISTINCT product) AS num_sold,
    GROUP_CONCAT(
        DISTINCT product
        ORDER BY product
        SEPARATOR ','
    ) AS products
FROM Activities
GROUP BY sell_date
ORDER BY sell_date, product
