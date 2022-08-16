SELECT  Sales.product_id AS product_id,
        product_name
FROM    Product
LEFT JOIN Sales
ON      Sales.product_id = Product.product_id
GROUP BY Sales.product_id
HAVING  MAX(sale_date) <= "2019-03-31"
AND     MIN(sale_date) >= "2019-01-01"