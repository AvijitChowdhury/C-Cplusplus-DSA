USE DUMMYDB;
CREATE TABLE Student(
	Roll VARCHAR(10) PRIMARY KEY,
    NAME VARCHAR(15));
CREATE TABLE Course(
	CourseNo VARCHAR(5) PRIMARY KEY,
    Date DATE
    );
CREATE TABLE Enroll(
	Roll VARCHAR(5),
    CourseNO VARCHAR(5),
    Date DATE,
    FOREIGN KEY (Roll) REFERENCES Student(Roll) ON DELETE CASCADE,
    FOREIGN KEY (CourseNo) REFERENCES Course(CourseNo) ON DELETE SET NULL
    );