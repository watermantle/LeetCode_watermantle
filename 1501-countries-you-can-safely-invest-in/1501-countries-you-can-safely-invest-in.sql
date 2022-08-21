SELECT  RF.name AS country
FROM    (
    SELECT  P.id,
            duration
    FROM    Person AS P
    LEFT JOIN Calls AS CA
    ON      P.id = CA.caller_id OR P.id = CA.callee_id
) AS TC
LEFT JOIN
(SELECT  id,
        C.name,
        country_code
FROM    Person AS P
LEFT JOIN Country AS C
ON      C.country_code = SUBSTRING(P.phone_number, 1, 3)
) AS RF
ON TC.id = RF.id
GROUP BY RF.country_code
HAVING AVG(TC.duration) > (SELECT AVG(duration) FROM Calls)

