SELECT  Day,
        `Cancellation Rate`
FROM    (
    SELECT  request_at AS Day,
            ROUND(SUM(
                CASE
                    WHEN client_banned = "No" AND driver_banned = "No" AND `status` LIKE "cancelled_by_%" THEN 1
                    ELSE 0
                END
            ) /  SUM(
                CASE
                    WHEN client_banned = "No" AND driver_banned = "No" THEN 1
                    ELSE 0
                END
            ), 2) AS `Cancellation Rate`
    FROM    (
        SELECT  id,
                `status`,
                A.banned AS client_banned,
                B.banned AS driver_banned,
                request_at
        FROM    Trips AS T
        LEFT JOIN Users AS A
        ON      T.client_id = A.users_id
        LEFT JOIN Users AS B
        ON      T.driver_id = B.users_id
        WHERE   request_at >= "2013-10-01"
        AND     request_at <= "2013-10-03"
    ) AS A
    GROUP BY request_at
    ORDER BY request_at
) AS B
WHERE   `Cancellation Rate` IS NOT NULL