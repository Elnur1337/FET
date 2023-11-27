CREATE UNIQUE INDEX uniqueNazPredUOrgJed ON pred (sifOrgjed, nazPred);
SELECT * FROM pred WHERE nazPred LIKE "%Mjerenja u elektrote%";


CREATE TEMPORARY TABLE orgjedPred AS
SELECT orgjed.* FROM orgjed
JOIN pred ON orgjed.sifOrgjed = pred.sifOrgjed
GROUP BY orgjed.sifOrgjed;
CREATE UNIQUE INDEX uniqueSifOrgjed ON orgjedPred (sifOrgjed);

CREATE TEMPORARY TABLE orgjedNast AS
SELECT orgjed.* FROM orgjed
JOIN nastavnik ON orgjed.sifOrgjed = nastavnik.sifOrgjed
GROUP BY orgjed.sifOrgjed;
CREATE UNIQUE INDEX uniqueSifOrgjed ON orgjedNast (sifOrgjed);


CREATE TEMPORARY TABLE testSerial (
	id SERIAL
);
SELECT * FROM testSerial;
INSERT INTO testSerial VALUES (0);
SELECT * FROM testSerial;
INSERT INTO testSerial VALUES (1);
SELECT * FROM testSerial;


CREATE TEMPORARY TABLE nastTemp
(
	rbrNast SERIAL,
	sifNastavnik INTEGER NOT NULL,
	imeNastavnik NCHAR(25) NOT NULL,
	prezNastavnik NCHAR(25) NOT NULL,
	pbrStan INTEGER NOT NULL,
	sifOrgjed INTEGER NOT NULL,
	koef DECIMAL(3,2) NOT NULL
);
INSERT INTO nastTemp SELECT 0, nastavnik.* FROM nastavnik;
SELECT * FROM nastTemp;


CREATE TEMPORARY TABLE studT AS SELECT * FROM stud;
CREATE TEMPORARY TABLE predT AS SELECT * FROM pred;
CREATE TEMPORARY TABLE nasT AS SELECT * FROM nastavnik;
CREATE TEMPORARY TABLE ispitT AS SELECT * FROM ispit;


UPDATE predT SET
nazPred = CONCAT(kratPred, "-", nazPred);


UPDATE nasT SET
koef = koef * 0.9
WHERE 
	sifNastavnik IN
    (SELECT sifNastavnik FROM ispit WHERE ocjena > 1 GROUP BY sifNastavnik HAVING AVG(ocjena) < 2.2)
	OR
    sifNastavnik IN
    (SELECT sifNastavnik FROM ispit WHERE ocjena = 1 GROUP BY sifNastavnik HAVING COUNT(ocjena) > 8);
    
    
UPDATE predT SET
brojSatiTjedno = brojSatiTjedno + 1
WHERE
	brojSatiTjedno BETWEEN 1 AND 5
    AND
	sifPred IN
    (SELECT sifPred FROM ispit WHERE datIspit > DATE_ADD(NOW(), INTERVAL -15 YEAR) AND ocjena = 1 GROUP BY sifPred HAVING COUNT(ocjena) > 10);


CREATE TEMPORARY TABLE ispitCount AS
SELECT sifPred, COUNT(ocjena) AS brojPetica FROM ispit WHERE ocjena = 5 GROUP BY 1 ORDER BY 2 DESC;
SELECT * FROM ispitCount;

UPDATE predT SET
brojSatiTjedno = brojSatiTjedno - 1
WHERE
	sifPred IN
    (SELECT sifPred FROM ispit WHERE ocjena = 5 GROUP BY sifPred HAVING COUNT(sifPred) = (SELECT MAX(brojPetica) FROM ispitCount));
	
    
CREATE TEMPORARY TABLE konverzija (
	sMbrStud INT NOT NULL,
    nMbrStud INT NOT NULL,
    nPbrRod INT NOT NULL,
    nPbrStan INT NOT NULL
);
LOAD DATA INFILE "C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/konverzija.unl" INTO TABLE konverzija FIELDS TERMINATED BY '#' LINES STARTING BY '\n' TERMINATED BY '#\r';
SELECT * FROM konverzija;
UPDATE studT SET
pbrRod = (SELECT nPbrRod FROM konverzija WHERE sMbrStud = studT.mbrStud);
UPDATE studT SET
pbrStan = (SELECT nPbrStan FROM konverzija WHERE sMbrStud = studT.mbrStud);
UPDATE studT SET
mbrStud = (SELECT nMbrStud FROM konverzija WHERE sMbrStud = studT.mbrStud);
UPDATE ispitT SET
mbrStud = (SELECT nMbrStud FROM konverzija WHERE sMbrStud = ispitT.mbrStud);


DELETE FROM studT WHERE prezStud RLIKE "^[AEIOU]";


DELETE FROM ispitT WHERE
	ispitT.sifNastavnik IN
    (SELECT sifNastavnik FROM nasT WHERE nasT.sifOrgjed IN (SELECT sifOrgjed FROM orgjed WHERE nazOrgjed LIKE "%fiziku%"));

DELETE FROM nasT WHERE
	nasT.sifOrgjed IN
    (SELECT sifOrgjed FROM orgjed WHERE nazOrgjed LIKE "%fiziku%");