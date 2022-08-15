SELECT  name,
        CASE
            WHEN A.dis IS NULL THEN 0
            WHEN A.dis IS NOT NULL THEN A.dis
        END AS travelled_distance 
FROM    Users
LEFT JOIN 
(SELECT  user_id,
        SUM(distance) AS dis
FROM    Rides
GROUP BY user_id
) AS A
ON      Users.id = A.user_id
ORDER BY travelled_distance DESC, name ASC