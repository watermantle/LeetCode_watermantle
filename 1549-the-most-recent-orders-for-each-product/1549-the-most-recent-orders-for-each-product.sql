SELECT  product_name,
        A.product_id,
        A.order_id,
        A.order_date
FROM    Products AS P
LEFT JOIN (
    SELECT  product_id,
            order_id,
            order_date,
            DENSE_RANK() OVER (PARTITION BY product_id ORDER BY order_date DESC) AS seq
    FROM    Orders AS O
) AS A
ON      P.product_id = A.product_id
WHERE   A.order_date IS NOT NULL
AND     A.seq = 1
ORDER BY product_name ASC, A.product_id ASC, A.order_id ASC

