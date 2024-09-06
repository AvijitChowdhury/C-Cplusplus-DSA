/*
Create a table of Employees which has the following fields
First Name
Last Name
Date of Birth
Department Id
Salary
Create a table of Departments which has the following fields
Department Id
Department Name
Create both of the tables using proper constraints

*/
CREATE DATABASE MIDTERM;
-- DROP DATABASE MIDTERM
USE MIDTERM;
CREATE TABLE DEPARTMENTS(
	DEPARTMENT_ID INT PRIMARY KEY,
    DEPARTMENT_NAME VARCHAR(20)
    );
CREATE TABLE EMPLOYEES(
	EMPLOYEE_ID INT ,
	FIRST_NAME VARCHAR(20) NOT NULL,
    	LAST_NAME VARCHAR(10) NOT NULL,
   	DATE_OF_BIRTH DATE NOT NULL,
   	DEPARTMENT_ID INT NOT NULL PRIMARY KEY,
   	SALARY INT,
   	FOREIGN KEY EMPLOYEES(DEPARTMENT_ID) REFERENCES     DEPARTMENTS(DEPARTMENT_ID));
/*
USING DUMMYDB
Write SQL Query to get the second max salary 
Write SQL Query to show  the department names and the average salary of the departments
 Illustrate the INNER, LEFT, RIGHT, SELF Joins
What is a subquery? Write with an example
Show the names of the employees who get less salary than Steven
Count the number of employees of each job type
Show the names of Departments which doesn’t have any employees


*/
USE DUMMYDB;
SELECT *
FROM EMPLOYEES
WHERE SALARY = (SELECT SALARY AS SECOND_HIGEST
				FROM EMPLOYEES
				ORDER BY SALARY DESC
                LIMIT 1
                OFFSET 1);
-- 5
SELECT DEPARTMENT_NAME, (SELECT AVG(SALARY) FROM EMPLOYEES WHERE DEPARTMENT_ID=EMPLOYEES.DEPARTMENT_ID) AS AVG_SALARY
FROM DEPARTMENTS;
-- 8
SELECT *
FROM EMPLOYEES
WHERE SALARY < (SELECT SALARY
				FROM EMPLOYEES
                WHERE FIRST_NAME ='STEVEN' AND LAST_NAME = 'KING');
-- 9
SELECT COUNT(*)
FROM EMPLOYEES;
-- 10
SELECT DEPARTMENTS.DEPARTMENT_NAME
FROM DEPARTMENTS
	LEFT JOIN EMPLOYEES
		ON DEPARTMENTS.DEPARTMENT_ID = EMPLOYEES.DEPARTMENT_ID
WHERE EMPLOYEES.DEPARTMENT_ID IS NULL;


