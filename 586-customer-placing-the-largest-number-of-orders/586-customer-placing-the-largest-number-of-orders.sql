SELECT  A.customer_number AS customer_number
FROM    (
    SELECT  COUNT(customer_number) AS feq,
            customer_number
    FROM Orders
    GROUP BY customer_number
    ORDER BY feq DESC
) AS A
LIMIT 1

