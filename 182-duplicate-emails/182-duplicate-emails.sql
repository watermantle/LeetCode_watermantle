SELECT  A.email AS Email
FROM    (
    SELECT  COUNT(email) AS fq,
            email
    FROM    Person
    GROUP BY email
) AS A
WHERE   A.fq > 1