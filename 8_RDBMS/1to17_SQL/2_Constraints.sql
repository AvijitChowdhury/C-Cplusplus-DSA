use programminghero;
-- drop table Student
CREATE TABLE Student(
	Roll CHAR(4) PRIMARY KEY,
    Name VARCHAR(10) NOT NULL,
    Email VARCHAR(30) UNIQUE,
    Address VARCHAR(255) ,
    Age INT CHECK(Age >= 10)
);
-- Inserting into table
INSERT INTO Student(Roll, Name, Email, Address, Age) Values ('101','Abijit','aby@gm','patharghata', 20);
-- second way of define
CREATE TABLE Student(
	Roll CHAR(4) ,
    Name VARCHAR(10) NOT NULL ,
    Email VARCHAR(12),
    Address VARCHAR(10),
    Age INT,
    PRIMARY KEY(Roll),
    UNIQUE(Email),
    CHECK(Age>=10)
);
-- thrid way of define
CREATE TABLE Student(
	Roll CHAR(4) ,
    Name VARCHAR(10) NOT NULL ,
    Email VARCHAR(12),
    Address VARCHAR(10),
    Age INT,
    CONSTRAINT pk_rule PRIMARY KEY(Roll),
    CONSTRAINT unique_rule UNIQUE(Email),
    CONSTRAINT checking_rule CHECK(Age>=10)
);
-- defining library
CREATE TABLE Library(
	BookName VARCHAR(20) PRIMARY KEY,
    WhoHired_Roll CHAR(4),
    FOREIGN KEY (WhoHired_Roll) REFERENCES Student(Roll)
);
-- composite primarykey
CREATE TABLE Course(
	CourseName VARCHAR(10),
    University VARCHAR(20),
    Credit INT,
    constraint compoPK PRIMARY KEY (CourseName,University) 
);