SELECT  B.name AS warehouse_name,
        SUM(B.units * B.unit_vol) AS volume
FROM
(SELECT  name,
        units,
        unit_vol
FROM    Warehouse
LEFT JOIN  (
    SELECT  product_id,
            Width * Length * Height AS unit_vol
    FROM    Products
) AS A
ON     Warehouse.product_id = A.product_id) AS B
GROUP BY B.name