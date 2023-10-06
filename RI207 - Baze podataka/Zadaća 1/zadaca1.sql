CREATE DATABASE EB22160 CHARACTER SET 'utf8mb4';
USE EB22160;
CREATE TABLE stud (
	mbrStud VARCHAR(8) PRIMARY KEY NOT NULL,
    prezStud VARCHAR(20) NOT NULL,
    imeStud VARCHAR(20) NOT NULL,
    datRodStud DATE,
    pbrRodStud INT,
    adrStud VARCHAR(40),
    prosOcjena DECIMAL(3,2) NOT NULL
);
SELECT * FROM stud;
INSERT INTO stud VALUES
('12345678', 'Bjelić', 'Elnur', '2002-11-09', 1, 'Krečanska 5F, Tuzla', 9.99),
('23456789', 'Delić', 'Amer', '2003-06-25', 1, 'Poljice bb', 9.99),
('34567891', 'Imamović', 'Amer', '2003-04-05', 1, 'Stupine, Tuzla', 9.99);
SELECT * FROM stud;
UPDATE stud SET prosOcjena = 8.99 WHERE mbrStud = '23456789';
SELECT * FROM stud INTO OUTFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/studenti.unl' FIELDS TERMINATED BY '#' LINES TERMINATED BY '\n';
DELETE FROM stud;
SELECT * FROM stud;
LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/studenti.unl' INTO TABLE stud FIELDS TERMINATED BY '#' LINES TERMINATED BY '\n';
DROP TABLE stud;