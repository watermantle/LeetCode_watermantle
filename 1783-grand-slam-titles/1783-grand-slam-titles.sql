SELECT  id AS player_id,
        player_name,
        grand_slams_count
FROM
(SELECT  id,
        SUM(num) AS grand_slams_count
FROM    (
    SELECT  Wimbledon AS id,
            COUNT(Wimbledon) AS num
    FROM    Championships
    GROUP BY Wimbledon
    UNION ALL
    SELECT  Fr_open AS id,
            COUNT(Fr_open) AS num
    FROM    Championships
    GROUP BY Fr_open
    UNION ALL
    SELECT  US_open AS id,
            COUNT(US_open) AS num
    FROM    Championships
    GROUP BY US_open
    UNION ALL
    SELECT  Au_open AS id,
            COUNT(Au_open) AS num
    FROM    Championships
    GROUP BY Au_open
) AS C
GROUP BY id
) AS B
LEFT JOIN Players AS P
ON B.id = P.player_id