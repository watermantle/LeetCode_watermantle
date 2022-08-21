SELECT  dept_name,
        IFNULL(COUNT(student_name), 0) AS student_number
FROM    Department AS D
LEFT JOIN Student AS S
ON      D.dept_id = S.dept_id
GROUP BY D.dept_id
ORDER BY student_number DESC, D.dept_name ASC