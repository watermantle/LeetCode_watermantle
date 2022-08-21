SELECT 
    A.student_id, 
    A.student_name, 
    A.subject_name, 
    IFNULL(attended_exams, 0) AS attended_exams
FROM 
    (
    SELECT  Students.student_id,
            Students.student_name,
            Subjects.subject_name
    FROM
    Students 
    CROSS JOIN Subjects) AS A
    LEFT JOIN (SELECT student_id, subject_name, COUNT(*) AS attended_exams 
               FROM Examinations 
               GROUP BY student_id, subject_name) AS B
    ON A.student_id = B.student_id AND A.subject_name = B.subject_name
ORDER BY student_id, subject_name;