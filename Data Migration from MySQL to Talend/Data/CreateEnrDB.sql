CREATE DATABASE enrolment;
USE enrolment;

CREATE TABLE  Student (
	 STUDNO   nchar (10) NOT NULL,
	 LNAME   nchar (20) NOT NULL,
	 FNAME   nchar (20) NOT NULL,
	 MNAME   nchar (20) NULL,
	 PROGRAM   nchar (10) NOT NULL,
	 YEARLEVEL   nchar (1) NOT NULL,
	 NATIONALITY   nchar (10) NULL,
	 GENDER   nchar (1) NOT NULL,
   PRIMARY KEY (STUDNO)
);


CREATE TABLE  Courses (
	 `COURSE CODE`   nchar (10) NOT NULL,
	 `COURSE TITLE`   nchar (50) NOT NULL,
	 UNITS   tinyint  NOT NULL,
	 `TUITION FEE`   double (10,2),
	 `LFD FEE`   double (10,2),
   PRIMARY KEY (`COURSE CODE`)
);


CREATE TABLE  SubjectsEnrolled (
	 `SY TERM`   nchar (11) NOT NULL,
	 STUDNO   nchar (10) NOT NULL,
	 `COURSE CODE`   nchar (10) NOT NULL,
	 SECTION   nchar (5) NOT NULL,
	 `FINAL GRADE`   nchar (5) NULL,
	 `C GRADE`   nchar (5) NULL,
	 REMARK   nchar (10) NULL
);

CREATE TABLE  StudentContact (
	 STUDNO   nchar (10) NOT NULL,
	 `PERMANENT ADDRESS`   nchar (100) NULL,
	 `MAILING ADDRESS`   nchar (100) NOT NULL,
	 TELEPHONE   nchar (30) NOT NULL,
	 EMAIL   nchar (50) NOT NULL,
   PRIMARY KEY (STUDNO) 
);

CREATE TABLE  Schedule (
	 `COURSE CODE`   nchar (10) NOT NULL,
	 SECTION   nchar (5) NOT NULL,
	 TIME   nchar (20) NOT NULL,
	 DAY   nchar (8) NOT NULL,
	 ROOM   nchar (10) NOT NULL,
	 PROFESSOR   nchar (30) NULL
);


CREATE TABLE  Form (
	 FormNumber   int  NOT NULL,
	 STUDNO   nchar (10) NOT NULL,
	 DATEPRINTED   date  NOT NULL,
    PRIMARY KEY (FormNumber)
);
