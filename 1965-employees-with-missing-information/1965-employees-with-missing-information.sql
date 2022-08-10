SELECT  A.employee_id
FROM    (
    SELECT  A.employee_id,
            name,
            salary 
    FROM    Employees AS A
    LEFT JOIN Salaries AS B
    ON      A.employee_id  = B.employee_id
    UNION
    SELECT  B.employee_id,
            name,
            salary
    FROM    Employees AS A
    RIGHT JOIN Salaries AS B
    ON      A.employee_id  = B.employee_id 
) AS A
WHERE   A.salary IS NULL
OR      A.name IS NULL
ORDER BY A.employee_id ASC
