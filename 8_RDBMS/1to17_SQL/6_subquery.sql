
-- USING DUMMY DATABASE
-- SUBQUERY 1
SELECT *
FROM EMPLOYEES
WHERE SALARY < (
			SELECT SALARY
            FROM EMPLOYEES
            WHERE EMPLOYEE_ID = 144);
-- HIGEST SALARY
use DUMMYDB;
SELECT * 
FROM EMPLOYEES
WHERE SALARY < (SELECT SALARY
				FROM EMPLOYEES
				WHERE EMPLOYEE_ID = 144);
-- THOSE EMPLOYEES BELONG TO MARKETING DEPARTMENT
SELECT *
FROM EMPLOYEES
WHERE DEPARTMENT_ID = (
				SELECT DEPARTMENT_ID
                FROM DEPARTMENTS
                WHERE DEPARTMENT_NAME='MARKETING'
                );
-- AVERAGE SALARY OF EMPLOYEES FROM MARKETING DEPARTMENT
SELECT AVG(SALARY)
FROM EMPLOYEES
WHERE DEPARTMENT_ID = (
				SELECT DEPARTMENT_ID
                FROM DEPARTMENTS
                WHERE DEPARTMENT_NAME='MARKETING'
                );
-- EMPLOYEES NUMBER WHO WORKED IN IT DEPARTMENT
SELECT COUNT(*)
FROM EMPLOYEES
WHERE DEPARTMENT_ID = (
				SELECT DEPARTMENT_ID
                FROM DEPARTMENTS
                WHERE DEPARTMENT_NAME='IT'
                );
-- OUTPUT AS COLUMN NAME MEMBERS
SELECT COUNT(*) AS MEMBERS
FROM EMPLOYEES
WHERE DEPARTMENT_ID = (
				SELECT DEPARTMENT_ID
                FROM DEPARTMENTS
                WHERE DEPARTMENT_NAME='IT'
                );
-- SUM OF SALARY OF ALL PROGRAMMER EMPLOYEES
SELECT SUM(SALARY)
FROM EMPLOYEES
WHERE JOB_ID = (SELECT JOB_ID
				FROM JOBS
                WHERE JOB_TITLE = 'PROGRAMMER'
                );