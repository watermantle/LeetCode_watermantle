# Write your MySQL query statement below
SELECT Weather.Id
FROM
    Weather
    JOIN Weather AS w
    ON DATEDIFF(Weather.recordDate, w.recordDate) = 1
    WHERE Weather.Temperature > w.Temperature