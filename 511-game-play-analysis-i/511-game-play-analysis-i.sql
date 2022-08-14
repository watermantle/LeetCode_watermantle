SELECT  A.player_id AS player_id,
        A.event_date AS first_login
FROM    (
    SELECT  player_id,
            event_date,
            ROW_NUMBER() OVER(PARTITION BY player_id ORDER BY event_date ASC) AS seq
    FROM Activity
) AS A
WHERE A.seq = 1

