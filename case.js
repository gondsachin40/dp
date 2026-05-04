SELECT ct , cnt , 
    CASE 
        WHEN cnt >= 5 THEN '*****'
        WHEN cnt = 4  THEN '****'
        WHEN cnt = 3  THEN '***'
        WHEN cnt = 2  THEN '**'
        ELSE '*' 
    END AS STAR
FROM (SELECT Country as ct , count(Country) AS cnt FROM Customers GROUP BY Country) AS TABLE1 ORDER BY cnt ASC;
