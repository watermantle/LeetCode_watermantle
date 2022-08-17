SELECT  P.product_id AS product_id,
        ROUND(SUM(P.price * U.units) / SUM(U.units), 2) AS average_price
FROM    Prices AS P
LEFT JOIN UnitsSold AS U
ON      P.product_id = U.product_id
WHERE   U.purchase_date <= P.end_date
AND     U.purchase_date >= P.start_date
GROUP BY P.product_id