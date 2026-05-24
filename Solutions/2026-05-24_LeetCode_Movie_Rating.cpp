/*

Problem Name   : Movie Rating
Platform       : LeetCode
Topic          : Database
Problem Link   : https://leetcode.com/problems/movie-rating/submissions/2011510000/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-05-24

*/

(
    SELECT name AS results
    FROM Users
    INNER JOIN MovieRating USING(user_id)
    GROUP BY user_id
    ORDER BY COUNT(rating) DESC, name
    LIMIT 1
)
UNION ALL 
(
    SELECT title AS results
    FROM Movies
    INNER JOIN MovieRating USING(movie_id)
    WHERE MONTH(created_at) = '02' AND YEAR(created_at) = '2020'
    GROUP BY title
    ORDER BY AVG(rating) DESC, title
    LIMIT 1
)
