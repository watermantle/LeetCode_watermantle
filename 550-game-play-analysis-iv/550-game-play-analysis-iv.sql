SELECT  ROUND(COUNT(B.player_id) / COUNT(A.player_id), 2) AS fraction
FROM
(SELECT  player_id,
        MIN(event_date) AS first_login
FROM    Activity AS A
GROUP BY player_id) AS A
LEFT JOIN Activity AS B
ON      A.player_id = B.player_id
AND     A.first_login = B.event_date - 1