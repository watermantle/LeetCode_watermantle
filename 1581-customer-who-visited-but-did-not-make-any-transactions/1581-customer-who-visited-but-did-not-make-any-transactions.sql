SELECT D.*
FROM (
    SELECT  C.customer_id AS customer_id,
            SUM(C.ind) AS count_no_trans 
    FROM    (
        SELECT  customer_id,
                CASE
                    WHEN V.visit_id NOT IN (SELECT DISTINCT visit_id FROM Transactions) THEN 1
                    ELSE 0
                END AS ind
        FROM    Visits AS V
    ) AS C
    GROUP BY C.customer_id
) AS D
WHERE D.count_no_trans != 0
