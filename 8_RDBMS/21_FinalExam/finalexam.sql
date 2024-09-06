CREATE DATABASE STUDENTLIB;

USE STUDENTLIB;
CREATE TABLE Student (
StudentID INT AUTO_INCREMENT PRIMARY KEY,
Name VARCHAR(255) NOT NULL,
Email VARCHAR(255) NOT NULL,
Phone VARCHAR(15),
Address TEXT
);
CREATE TABLE Book (
ISBN VARCHAR(13) PRIMARY KEY,
Title VARCHAR(255) NOT NULL,
Author VARCHAR(255) NOT NULL,
Genre VARCHAR(50),
TotalCopies INT NOT NULL,
AvailableCopies INT NOT NULL
);
CREATE TABLE Borrowing (
BorrowID INT AUTO_INCREMENT PRIMARY KEY,
StudentID INT,
ISBN VARCHAR(13),
BorrowDate DATE NOT NULL,
DueDate DATE NOT NULL,
ReturnDate DATE,
FOREIGN KEY (StudentID) REFERENCES Student(StudentID),
FOREIGN KEY (ISBN) REFERENCES Book(ISBN)
);
-- query 2
INSERT INTO Borrowing (StudentID, ISBN, BorrowDate, DueDate) 
VALUES (3, (SELECT ISBN FROM Book ORDER BY AvailableCopies DESC LIMIT 1), '2023-10-13','2023-10-27');
-- query 3
UPDATE Book
SET AvailableCopies=AvailableCopies-1
WHERE ISBN ='9781234567890';
-- query 4
SELECT Student.Name
FROM Student
INNER JOIN Borrowing ON Student.StudentID = Borrowing.StudentID
GROUP BY Student.StudentID
ORDER BY COUNT(*) DESC
LIMIT 1;
-- query 5
SELECT *
FROM Book
INNER JOIN Borrowing ON Book.ISBN = Borrowing.ISBN
WHERE Borrowing.ReturnDate IS NULL AND Borrowing.DueDate < CURDATE();
-- query 8
SELECT MAX(SALARY)
FROM Employee
WHERE SALARY< (SELECT MAX(SALARY)
			   FROM Employee);
-- query 9
CREATE TABLE Employee(
	EmployeeID VARCHAR(5) PRIMARY KEY,
    Name VARCHAR(10),
    DepartmentID INT
);
CREATE TABLE JobHistory(
	JobHistoryId INT PRIMARY KEY,
    EmployeeID INT,
    StartDate DATE NOT NULL,
    EndDate DATE
    );
CREATE TABLE Department(
	DepartmentID INT PRIMARY KEY,
    DepartmentName VARCHAR(15)
    );
-- drop table employee
-- drop table jobhistory
-- drop table department
ALTER TABLE JobHistory
ADD FOREIGN KEY (EmployeeID) REFERENCES Employee(EmployeeID) ON DELETE CASCADE;
ALTER TABLE Employee
ADD FOREIGN KEY (DepartmentID) REFERENCES Department(DepartmentID) ON DELETE SET NULL;

