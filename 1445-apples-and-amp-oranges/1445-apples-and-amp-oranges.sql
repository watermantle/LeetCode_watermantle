SELECT  apple.sale_date AS sale_date,
        apple.num_apples - orange.num_oranges AS diff
FROM
(
    SELECT  sale_date,
            CASE
                WHEN fruit = "apples" THEN sold_num
            END AS num_apples
    FROM    Sales
    GROUP BY sale_date
) AS apple
LEFT JOIN (
    SELECT  A.sale_date AS sale_date,
            num_oranges
    FROM    (
        SELECT  sale_date,
                CASE
                    WHEN fruit = "oranges" THEN sold_num
                END AS num_oranges
        FROM    Sales
    ) AS A
    WHERE num_oranges IS NOT NULL
) AS orange
ON apple.sale_date = orange.sale_date
ORDER BY apple.sale_date