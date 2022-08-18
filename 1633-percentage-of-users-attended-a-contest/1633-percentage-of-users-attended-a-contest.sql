SELECT  A.contest_id,
        A.percentage
FROM
(SELECT  contest_id,
        ROUND(COUNT(user_id) / (SELECT COUNT(user_id) FROM Users) * 100, 2) AS percentage
FROM    Register
GROUP BY contest_id
) AS A
ORDER BY A.percentage DESC, A.contest_id ASC