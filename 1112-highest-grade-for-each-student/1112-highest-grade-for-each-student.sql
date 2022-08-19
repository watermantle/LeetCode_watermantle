SELECT  A.student_id,
        A.course_id,
        A.grade
FROM    (
    SELECT  student_id,
            ROW_NUMBER() OVER(PARTITION BY student_id ORDER BY grade DESC, course_id ASC) AS rnk_grade,
            course_id,
            grade
    FROM    Enrollments
) AS A
WHERE   rnk_grade = 1
ORDER BY A.student_id ASC