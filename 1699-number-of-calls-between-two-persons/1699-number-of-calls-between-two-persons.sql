SELECT  A.person1,
        A.person2,
        SUM(A.duration) AS total_duration,
        COUNT(A.duration) AS call_count
FROM
(
SELECT CASE
            WHEN from_id < to_id THEN from_id
            ELSE to_id
        END AS person1,
        CASE
            WHEN from_id > to_id THEN from_id
            ELSE to_id
        END AS person2,
        duration
FROM    Calls) AS A
GROUP BY A.person1, A.person2