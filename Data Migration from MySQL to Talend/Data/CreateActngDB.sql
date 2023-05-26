CREATE DATABASE accounting;
USE accounting;

CREATE TABLE  Payments (
	 ORNumber   int  NOT NULL ,
	 STUDNO   nchar (15) NULL,
	 AmountPaid   double (10,2),
	 Date   nchar (10) NULL,
	 SYTerm   nchar (11) NULL,
   PRIMARY KEY (ORNumber)
); 

CREATE TABLE  ModeOfPayment (
	 STUDNO   nchar (10) NOT NULL,
	 MODEOFPAYMENT   nchar (15) NOT NULL
);

CREATE TABLE  MiscellaneousFees (
	 FeeCode   nchar (10) NOT NULL,
	 FeeDescription   nchar (25) NOT NULL,
	 Amount   double (10,2),
   PRIMARY KEY (FeeCode)
);

CREATE TABLE  Assessment (
	 STUDNO   nchar (15) NOT NULL,
	 FeeCode   nchar (10) NOT NULL,
	 Amount    double (10,2),
	 FeeType   nchar (3) NULL
);
