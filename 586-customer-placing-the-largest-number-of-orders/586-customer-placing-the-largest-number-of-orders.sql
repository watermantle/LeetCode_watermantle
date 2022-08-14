SELECT  A.customer_number AS customer_number
FROM    (
    SELECT  customer_number,
            ROW_NUMBER() OVER(PARTITION BY customer_number) AS seq
    FROM Orders
    ORDER BY seq DESC
    LIMIT 1
) AS A




