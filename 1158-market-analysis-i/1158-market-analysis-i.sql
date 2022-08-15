SELECT  user_id AS buyer_id,
        join_date,
        CASE
            WHEN A.frq IS NULL THEN 0
            ELSE A.frq
        END AS orders_in_2019
FROM    Users
LEFT JOIN
(SELECT  buyer_id,
        COUNT(buyer_id) AS frq
FROM    Orders
WHERE   order_date >= "2019-01-01"
AND     order_date <= "2019-12-31"
GROUP BY buyer_id) AS A
ON      Users.user_id = A.buyer_id