-- 1. Create tables 
-- a. Make a student table b. Make a Library table c. Make a Fees table Create table with proper relations.

CREATE TABLE student(
	Roll VARCHAR(5) PRIMARY KEY,
    Name VARCHAR(15) NOT NULL,
    Email VARCHAR(30) UNIQUE,
    Address VARCHAR(20) NOT NULL,
    Age INT CHECK(Age<15)
    );
CREATE TABLE Library(
	BookName VARCHAR(30) PRIMARY KEY,
    WHohiredroll CHAR(5),
    foreign key (WHohiredroll) REFERENCES student(Roll)
    );
CREATE TABLE fees(
	AmountPaid CHAR(10) PRIMARY KEY,
    PaidAmountRoll VARCHAR(30) NOT NULL,
    FOREIGN KEY (PaidAmountRoll) REFERENCES student(Roll)
);