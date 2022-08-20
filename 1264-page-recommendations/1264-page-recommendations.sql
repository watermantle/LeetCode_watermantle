SELECT  page_id AS recommended_page
FROM
(
SELECT A.user_id,
        L.page_id
FROM (
    SELECT  CASE
                WHEN user1_id = 1 THEN user2_id
                WHEN user2_id = 1 THEN user1_id
            END AS user_id
    FROM    Friendship) AS A
LEFT JOIN Likes AS L
ON A.user_id = L.user_id
WHERE A.user_id IS NOT NULL
AND L.page_id NOT IN (SELECT page_id FROM Likes WHERE user_id = 1)) AS B
GROUP BY page_id

