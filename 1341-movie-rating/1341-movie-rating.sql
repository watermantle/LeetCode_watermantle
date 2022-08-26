(SELECT  name AS results
FROM    Users AS U
LEFT JOIN (
    SELECT  user_id,
            DENSE_RANK() OVER (ORDER BY COUNT(movie_id) DESC) AS rnk
    FROM    MovieRating AS M
    GROUP BY user_id
) AS A
ON      U.user_id = A.user_id
WHERE   rnk = 1
ORDER BY name ASC
LIMIT 1)

UNION

(SELECT  title AS results
FROM    Movies AS M
LEFT JOIN
(SELECT  movie_id,
        DENSE_RANK() OVER (ORDER BY AVG(rating) DESC) AS rnk
FROM    MovieRating AS M
WHERE   YEAR(created_at) = "2020"
AND     MONTH(created_at) = '02'
GROUP BY movie_id
) AS A
ON      M.movie_id = A.movie_id
WHERE   A.rnk = 1
ORDER BY title ASC
LIMIT   1)