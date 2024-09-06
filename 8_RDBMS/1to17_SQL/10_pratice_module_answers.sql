-- Determine the third highest salary and which employee receives it?
USE DUMMYDB;
SELECT * 
FROM EMPLOYEES
WHERE SALARY = (
		SELECT SALARY 
		FROM EMPLOYEES
		ORDER BY SALARY DESC
		LIMIT 1
		OFFSET 2);
-- Determine the third lowest salary and which employee receives it?
SELECT * 
FROM EMPLOYEES
WHERE SALARY = (
		SELECT SALARY 
		FROM EMPLOYEES
		ORDER BY SALARY ASC
		LIMIT 1
		OFFSET 2);
-- Which employee has been hired after Steven?
SELECT *
FROM EMPLOYEES
WHERE HIRE_DATE>(  SELECT HIRE_DATE 
				   FROM EMPLOYEES
				   WHERE FIRST_NAME ='STEVEN' AND LAST_NAME ='KING');
-- With common table expression solve the question 1 and 2
WITH TEMP AS (
		SELECT SALARY 
		FROM EMPLOYEES
		ORDER BY SALARY DESC
        LIMIT 1
		OFFSET 2)
SELECT * 
FROM EMPLOYEES
WHERE SALARY = (
		SELECT SALARY AS TEMP 
		);