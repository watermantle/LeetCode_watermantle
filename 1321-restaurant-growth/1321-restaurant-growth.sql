SELECT  A.visited_on, SUM(B.subSUm) AS amount, ROUND(AVG(B.subSum), 2) AS average_amount
FROM    
(SELECT visited_on, SUM(amount) AS subSum FROM Customer GROUP BY visited_on) AS A,
(SELECT visited_on, SUM(amount) AS subSum FROM Customer GROUP BY visited_on) AS B
WHERE   DATEDIFF(A.visited_on, B.visited_on) BETWEEN 0 AND 6
GROUP BY A.visited_on
HAVING  COUNT(B.visited_on) = 7