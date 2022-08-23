SELECT  E.employee_id,
        E.name,
        A.rpt_count AS reports_count,
        A.avg_age AS average_age
FROM    (
    SELECT  E.reports_to AS id,
            ROUND(AVG(age), 0) AS avg_age,
            COUNT(age) AS rpt_count
    FROM    Employees AS E
    WHERE   reports_to IS NOT NULL
    GROUP BY reports_to
) AS A
JOIN Employees AS E
ON      E.employee_id = A.id
ORDER BY E.employee_id