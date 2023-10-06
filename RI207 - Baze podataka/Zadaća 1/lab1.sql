CREATE TABLE stud (
	mbrStud VARCHAR(8) PRIMARY KEY NOT NULL,
    prezStud VARCHAR(20) NOT NULL,
    imeStud VARCHAR(20) NOT NULL,
    datRodStud DATE,
    pbrRodStud INT,
    adrStud VARCHAR(40),
    prosOcjena DECIMAL(3,2) NOT NULL
);
LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/studenti.unl' INTO TABLE stud FIELDS TERMINATED BY '#' LINES TERMINATED BY '\n';
SELECT * FROM stud;