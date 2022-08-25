SELECT  customer_id
FROM    Customer AS C
GROUP BY customer_id
HAVING  COUNT(DISTINCT product_key) = (SELECT COUNT(DISTINCT product_key) FROM Customer AS C)