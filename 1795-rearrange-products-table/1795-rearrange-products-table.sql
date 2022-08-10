SELECT  product_id,
        CASE
            WHEN store1 IS NOT NULL THEN 'store1'
        END AS store,
        CASE
            WHEN store1 IS NOT NULL THEN store1
        END AS price
FROM    Products
WHERE   store1 IS NOT NULL
UNION
SELECT  product_id,
        CASE
            WHEN store2 IS NOT NULL THEN 'store2'
        END AS store,
        CASE
            WHEN store2 IS NOT NULL THEN store2
        END AS price
FROM    Products
WHERE   store2 IS NOT NULL
UNION
SELECT  product_id,
        CASE
            WHEN store3 IS NOT NULL THEN 'store3'
        END AS store,
        CASE
            WHEN store3 IS NOT NULL THEN store3
        END AS price
FROM    Products
WHERE store3 IS NOT NULL