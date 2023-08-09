Input: 
Activity table:
+-----------+-----------+------------+--------------+
| player_id | device_id | event_date | games_played |
+-----------+-----------+------------+--------------+
| 1         | 2         | 2016-03-01 | 5            |
| 1         | 2         | 2016-03-02 | 6            |
| 2         | 3         | 2017-06-25 | 1            |
| 3         | 1         | 2016-03-02 | 0            |
| 3         | 4         | 2018-07-03 | 5            |
+-----------+-----------+------------+--------------+
Output: 
+-----------+
| fraction  |
+-----------+
| 0.33      |
+-----------+
Explanation: 
Only the player with id 1 logged back in after the first day he had logged in so the answer is 1/3 = 0.33

# DATEDIFF(event_date, MIN(event_date) OVER(PARTITION BY player_id)) = 1 返回是否(1/0)
SELECT
   ROUND(SUM(login)/COUNT(DISTINCT player_id), 2) AS fraction
FROM (
  SELECT
    player_id,
    DATEDIFF(event_date, MIN(event_date) OVER(PARTITION BY player_id)) = 1 AS login
  FROM Activity
) AS t