SELECT  Department,
        Employee,
        salary AS Salary
FROM    
(SELECT E.name AS Employee,
        D.name AS Department,
        salary,
        departmentId,
        RANK() OVER(PARTITION BY departmentId ORDER BY salary DESC) AS rnk
FROM    Employee AS E
LEFT JOIN Department AS D
ON      E.departmentId = D.id) AS A
WHERE   A.rnk = 1