SELECT DISTINCT product_id, 10 AS price
FROM Products
GROUP BY product_id
HAVING (MIN(change_date) > "2019-08-16")
UNION
SELECT  product_id,
        new_price AS price
FROM    (
    SELECT  product_id,
            new_price,
            ROW_NUMBER() OVER(PARTITION BY product_id ORDER BY change_date DESC) AS rnk
    FROM    Products AS P
    WHERE   change_date <= "2019-08-16"
) AS A
WHERE rnk = 1

