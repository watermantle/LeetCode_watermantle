SELECT  C.customer_id,
        customer_name
FROM    Customers AS C
LEFT JOIN Orders AS O
ON      C.customer_id = O.customer_id
GROUP BY customer_id
HAVING SUM(O.product_name = 'A') > 0 AND SUM(O.product_name = 'B') > 0 AND SUM(O.product_name = 'C') = 0
ORDER BY customer_id