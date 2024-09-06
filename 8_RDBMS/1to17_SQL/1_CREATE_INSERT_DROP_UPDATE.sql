-- creating database named programming hero
CREATE DATABASE programminghero;
-- using current databse
USE programminghero;
-- Creating table named student
CREATE TABLE Student(
	Roll CHAR(4) primary key,
    Name VARCHAR(50),
    Marks DOUBLE
);
-- inserting elements into database
INSERT INTO Student(Roll,Name, Marks) VALUES('1001','Avroneel',50);
-- Checking values
SELECT * FROM programminghero.student;
-- Drop table
DROP TABLE Student;
-- Updating name
SET SQL_SAFE_UPDATES = 0;
UPDATE Student
SET Name='Avijit Chowdhury'
WHERE Roll='1001';
SET SQL_SAFE_UPDATES = 1;
-- delete 
SET SQL_SAFE_UPDATES = 0;
DELETE FROM Student
WHERE Roll = '1001';
SET SQL_SAFE_UPDATES = 1;