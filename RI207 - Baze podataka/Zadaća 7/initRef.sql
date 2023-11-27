CREATE DATABASE stusluEB CHARACTER SET = 'utf8' COLLATE = 'utf8_croatian_ci';
USE stusluEB;

CREATE TABLE zupanija
(
	sifZupanija SMALLINT PRIMARY KEY,
	nazZupanija NCHAR(40) NOT NULL
);

CREATE TABLE mjesto
(
	pbr INTEGER PRIMARY KEY,
    nazMjesto NCHAR(40) NOT NULL UNIQUE,
    sifZupanija SMALLINT,
    FOREIGN KEY (sifZupanija) REFERENCES zupanija(sifZupanija)
);

CREATE TABLE stud
(
	mbrStud INTEGER PRIMARY KEY,
    imeStud NCHAR(25) NOT NULL,
    prezStud NCHAR(25) NOT NULL,
    pbrRod INTEGER,
    pbrStan INTEGER NOT NULL,
    datRodStud DATE,
    jmbgStud CHAR(13),
    FOREIGN KEY (pbrRod) REFERENCES mjesto(pbr),
    FOREIGN KEY (pbrStan) REFERENCES mjesto(pbr)
);

CREATE TABLE orgjed
(
	sifOrgjed INTEGER PRIMARY KEY,
    nazOrgjed NCHAR(60) NOT NULL,
    sifNadorgjed INTEGER,
    FOREIGN KEY (sifNadorgjed) REFERENCES orgjed(sifOrgjed)
);

CREATE TABLE nastavnik
(
	sifNastavnik INTEGER PRIMARY KEY,
    imeNastavnik NCHAR(25) NOT NULL,
    prezNastavnik NCHAR(25) NOT NULL,
    pbrStan INTEGER NOT NULL,
    sifOrgjed INTEGER NOT NULL,
    koef DECIMAL(3,2) NOT NULL,
    FOREIGN KEY (pbrStan) REFERENCES mjesto(pbr),
    FOREIGN KEY (sifOrgjed) REFERENCES orgjed(sifOrgjed)
);

CREATE TABLE pred
(
	sifPred INTEGER PRIMARY KEY,
    kratPred CHAR(8),
    nazPred NCHAR(60) NOT NULL,
    sifOrgjed INTEGER,
    upisanoStud INTEGER,
    brojSatiTjedno INTEGER,
    FOREIGN KEY (sifOrgjed) REFERENCES orgjed(sifOrgjed)
);

CREATE TABLE ispit
(
	mbrStud INTEGER NOT NULL,
    sifPred INTEGER NOT NULL,
    sifNastavnik INTEGER NOT NULL,
    datIspit DATE NOT NULL,
    ocjena SMALLINT DEFAULT 1 NOT NULL,
    PRIMARY KEY (mbrStud, sifPred, datIspit)
);

CREATE TABLE dvorana
(
	oznDvorana CHAR(5) PRIMARY KEY,
    kapacitet INTEGER DEFAULT 40
);

CREATE TABLE rezervacija
(
	oznDvorana CHAR(5) NOT NULL,
    oznVrstaDan CHAR(2) NOT NULL,
    sat SMALLINT NOT NULL,
    sifPred INTEGER NOT NULL,
    PRIMARY KEY (oznDvorana, oznVrstaDan, sat),
    FOREIGN KEY (oznDvorana) REFERENCES dvorana(oznDvorana)
);

LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/zupanija.unl' INTO TABLE zupanija FIELDS TERMINATED BY
'#' LINES STARTING BY '\n' TERMINATED BY '#\r';
LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/mjesto.unl' INTO TABLE mjesto FIELDS TERMINATED BY '#'
LINES STARTING BY '\n' TERMINATED BY '#\r';
LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/stud.unl' INTO TABLE stud FIELDS TERMINATED BY '#' LINES
STARTING BY '\n' TERMINATED BY '\r';
LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/orgjed.unl' INTO TABLE orgjed FIELDS TERMINATED BY '#'
LINES STARTING BY '\n' TERMINATED BY '#\r';
LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/nastavnik.unl' INTO TABLE nastavnik FIELDS TERMINATED BY
'#' LINES STARTING BY '\n' TERMINATED BY '#\r';
LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/pred.unl' INTO TABLE pred FIELDS TERMINATED BY '#' LINES
STARTING BY '\n' TERMINATED BY '#\r';
LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/ispit.unl' INTO TABLE ispit FIELDS TERMINATED BY '#'
LINES STARTING BY '\n';
LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/dvorana.unl' INTO TABLE dvorana FIELDS TERMINATED BY '#'
LINES STARTING BY '\n' TERMINATED BY '#\r';
LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/rezervacija.unl' INTO TABLE rezervacija FIELDS TERMINATED
BY '#' LINES STARTING BY '\n' TERMINATED BY '#\r';


INSERT INTO zupanija VALUES (0, "Poznata zupanija");
INSERT INTO dvorana VALUES ("Chamber of Secrets", 1337);