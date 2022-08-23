SELECT  C1.seat_id
FROM    Cinema AS C1
JOIN Cinema AS C2
ON      ABS(C1.seat_id - C2.seat_id) = 1
AND     C1.free = 1 AND C2.free = 1
GROUP BY C1.seat_id
ORDER BY C1.seat_id