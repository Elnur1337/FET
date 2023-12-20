CREATE TABLE diplom (
	mbrStud INTEGER NOT NULL,
	datPrijava DATE NOT NULL,
    sifMentor INTEGER,
    ocjenaRad SMALLINT,
    datObrana DATE,
    ukupOcjena SMALLINT,
    PRIMARY KEY (mbrStud, datPrijava),
    FOREIGN KEY (mbrStud) REFERENCES stud (mbrStud),
    FOREIGN KEY (sifMentor) REFERENCES nastavnik (sifNastavnik)
);

CREATE TABLE dipkom (
	mbrStud INTEGER NOT NULL,
    datPrijava DATE NOT NULL,
	sifNastavnik INTEGER NOT NULL, 
    oznUloga CHAR(1),
    ocjenaUsm SMALLINT,
    PRIMARY KEY (mbrStud, datPrijava, sifNastavnik),
    FOREIGN KEY (mbrStud, datPrijava) REFERENCES diplom (mbrStud, datPrijava), 
    FOREIGN KEY (mbrStud) REFERENCES stud (mbrStud),
    FOREIGN KEY (sifNastavnik) REFERENCES nastavnik (sifNastavnik)
);

LOAD DATA INFILE "C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/diplom.unl" INTO TABLE diplom FIELDS TERMINATED BY '#' LINES STARTING BY '\n' TERMINATED BY '#\r';
LOAD DATA INFILE "C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/dipkom.unl" INTO TABLE dipkom FIELDS TERMINATED BY '#' LINES STARTING BY '\n' TERMINATED BY '#\r';


DELIMITER //
CREATE PROCEDURE orgjedNast(id INTEGER)
BEGIN
	SELECT
		CONCAT(imeNastavnik, " ", prezNastavnik, ": ", orgjed.nazOrgjed, ", ", orgjedN.nazOrgjed)
	FROM nastavnik
    JOIN orgjed ON nastavnik.sifOrgjed = orgjed.sifOrgjed
    JOIN orgjed orgjedN ON orgjed.sifNadorgjed = orgjedN.sifOrgjed
    WHERE sifnastavnik = id;
END//

CALL orgjedNast(244);

DELIMITER //
CREATE FUNCTION noviKoef(id INTEGER)
RETURNS DECIMAL(3, 2) DETERMINISTIC
BEGIN
	DECLARE brPoOc INTEGER;
    DECLARE brNeOc INTEGER;
    DECLARE prOcPoNast DECIMAL(3, 2);
    DECLARE ukupPrOcPo DECIMAL(3, 2);
    DECLARE nkoef DECIMAL(3, 2);
    
    SELECT COUNT(*), AVG(ocjena) INTO brPoOc, prOcPoNast FROM ispit WHERE sifNastavnik = id AND ocjena > 1;
    SELECT COUNT(*) INTO brNeOc FROM ispit WHERE sifNastavnik = id AND ocjena = 1;
    SELECT AVG(ocjena) INTO ukupPrOcPo FROM ispit WHERE ocjena > 1;
    SELECT koef INTO nkoef FROM nastavnik WHERE sifNastavnik = id;
    
    IF ((brPoOc > brNeOc) AND (prOcPoNast > ukupPrOcPo)) THEN
		SET nkoef = nkoef * 1.1;
	ELSEIF ((brNeOc > brPoOc) AND (prOcPoNast < ukupPrOcPo)) THEN
		SET nkoef = nkoef * 0.9;
	END IF;
    RETURN nkoef;
END//

SELECT noviKoef(277);


DELIMITER //
CREATE FUNCTION ocjObrane(mbr INTEGER, dat DATE)
RETURNS SMALLINT DETERMINISTIC
BEGIN
	DECLARE ukOc SMALLINT;
	DECLARE ocRad SMALLINT;
    DECLARE brOc SMALLINT;
    DECLARE prosOc DECIMAL(3, 2);
    
    SELECT COUNT(*) INTO brOc FROM dipkom WHERE mbrStud = mbr AND datPrijava = dat;
    SELECT ocjenaRad INTO ocRad FROM diplom WHERE mbrStud = mbr AND datPrijava = dat;
    
    IF (ocRad IS NULL) THEN
		SET ukOc = 0;
    ELSEIF (brOc != 3 AND (1 NOT IN (SELECT ocjenaUsm FROM dipkom WHERE mbrStud = mbr AND datPrijava = dat) AND ocRad != 1)) THEN
		SET ukOc = 0;
    ELSEIF (ocRad = 1 OR (1 IN (SELECT ocjenaUsm FROM dipkom WHERE mbrStud = mbr AND datPrijava = dat))) THEN
		SET ukOc = 1;
	ELSE
		SELECT AVG(ocjenaUsm) INTO prosOc FROM dipkom WHERE mbrStud = mbr AND datPrijava = dat;
        SET ukOc = ROUND(prosOc);
	END IF;
    RETURN ukOc;
END//

SELECT ocjObrane(1127, '2045-01-21');

SELECT 
	*,
    ocjObrane(mbrStud, datPrijava)
    FROM diplom
	ORDER BY mbrStud, datPrijava;