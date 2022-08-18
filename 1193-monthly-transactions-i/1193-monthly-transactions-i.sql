SELECT  A.month AS month,
        A.country AS country,
        COUNT(A.state) AS trans_count,
        SUM(CASE WHEN A.state = "approved" THEN 1 ELSE 0 END) AS approved_count,
        SUM(A.amount) AS trans_total_amount,
        SUM(CASE WHEN A.state = "approved" THEN A.amount ELSE 0 END) AS approved_total_amount
FROM
(SELECT  CONCAT(YEAR(trans_date), "-", LPAD(MONTH(trans_date), 2, 0)) AS month,
        country,
        state,
        amount
FROM    Transactions
) AS A
GROUP BY A.month, A.country



