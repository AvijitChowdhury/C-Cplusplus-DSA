USE DUMMYDB;
WITH TEMP AS(	
SELECT *
FROM EMPLOYEES
LIMIT 5
)
SELECT *
FROM TEMP;
