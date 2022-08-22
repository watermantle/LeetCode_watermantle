SELECT  player_id,
        player_name,
        SUM(Wimbledon = player_id) + SUM(Fr_open = player_id) + SUM(US_open = player_id) + SUM(Au_open = player_id) AS grand_slams_count
FROM    Championships AS C
JOIN    Players AS P
ON      P.player_id = C.Wimbledon OR P.player_id = C.Fr_open OR P.player_id = C.US_open OR P.player_id = C.Au_open
GROUP BY player_id