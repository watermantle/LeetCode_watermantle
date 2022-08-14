SELECT  A.user_id AS user_id,
        A.time_stamp AS last_stamp
FROM    (
    SELECT  user_id,
            time_stamp,
            ROW_NUMBER() OVER(PARTITION BY user_id ORDER BY time_stamp DESC) AS seq
    FROM    Logins
    WHERE   time_stamp >= "2020-01-01"
    AND     time_stamp < "2021-01-01"
) AS A
WHERE   A.seq = 1