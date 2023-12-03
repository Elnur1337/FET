START TRANSACTION;
SET autocommit=0;
ALTER TABLE nastavnik MODIFY sifOrgjed INTEGER;
ALTER TABLE nastavnik MODIFY pbrStan INTEGER;
ALTER TABLE nastavnik ADD CONSTRAINT FOREIGN KEY (sifOrgjed) REFERENCES orgjed (sifOrgjed);
ALTER TABLE nastavnik ADD CONSTRAINT FOREIGN KEY (pbrStan) REFERENCES mjesto (pbr);

UPDATE nastavnik SET sifOrgjed = NULL
WHERE sifOrgjed = (SELECT sifOrgjed FROM orgjed WHERE nazOrgjed = "Zavod za primijenjenu fiziku");

UPDATE pred SET sifOrgjed = NULL
WHERE sifOrgjed = (SELECT sifOrgjed FROM orgjed WHERE nazOrgjed = "Zavod za primijenjenu fiziku");

CREATE TEMPORARY TABLE orgjedTemp AS SELECT * FROM orgjed;
UPDATE orgjed SET sifNadorgjed = NULL
WHERE sifNadorgjed = (SELECT sifOrgjed FROM orgjedTemp WHERE nazOrgjed = "Zavod za primijenjenu fiziku");

DELETE FROM orgjed WHERE nazOrgjed = "Zavod za primijenjenu fiziku";


UPDATE nastavnik SET pbrStan = NULL
WHERE
	imeNastavnik LIKE "D%"
    AND
    prezNastavnik LIKE "J%";


SELECT COUNT(sifNastavnik) FROM nastavnik
WHERE
	pbrStan IS NULL 
    OR
    sifOrgjed IS NULL;

SELECT COUNT(sifPred) FROM pred
WHERE
	sifOrgjed = 100002
    AND
    sifOrgjed IS NOT NULL;
    
SELECT COUNT(sifPred) FROM pred;


SELECT * FROM pred WHERE sifOrgjed IS NOT NULL;


SELECT * FROM pred WHERE sifOrgjed IS NULL;


SELECT COUNT(sifPred) FROM pred
WHERE sifOrgjed IS NOT NULL;


SELECT COUNT(DISTINCT sifOrgjed) FROM nastavnik WHERE sifOrgjed IS NOT NULL;


SELECT
	DISTINCT brojSatiTjedno,
    sifOrgjed,
    COUNT(sifPred)
FROM pred
WHERE
	brojSatiTjedno IS NOT NULL
    AND
    sifOrgjed IS NOT NULL
GROUP BY 1, 2;


SELECT * FROM stud
WHERE pbrStan != ALL (SELECT DISTINCT pbrRod FROM stud);


SELECT
	sifNastavnik,
    prezNastavnik,
    imeNastavnik,
    nastavnik.sifOrgjed,
    IF(nastavnik.sifOrgjed IS NOT NULL, orgjed.nazOrgjed, "NULL") AS nazOrgjed
FROM nastavnik
LEFT JOIN orgjed ON nastavnik.sifOrgjed = orgjed.sifOrgjed;


SELECT
	sifNastavnik,
    prezNastavnik,
    imeNastavnik,
    nastavnik.sifOrgjed,
    orgjed.nazOrgjed,
    orgjedNad.nazOrgjed AS nazNadOrgjed
FROM nastavnik
LEFT JOIN orgjed ON nastavnik.sifOrgjed = orgjed.sifOrgjed
LEFT JOIN orgjed AS orgjedNad ON orgjed.sifNadorgjed = orgjedNad.sifOrgjed;


SELECT
	sifNastavnik,
    prezNastavnik,
    imeNastavnik,
    pbrStan,
    nazMjesto,
    nastavnik.sifOrgjed,
    nazOrgjed
FROM nastavnik
LEFT JOIN mjesto ON pbrStan = pbr
LEFT JOIN orgjed ON nastavnik.sifOrgjed = orgjed.sifOrgjed
ORDER BY  5, 2;

SELECT
	sifNastavnik,
    prezNastavnik,
    imeNastavnik,
    pbrStan,
    nazMjesto,
    nazZupanija
FROM nastavnik
LEFT JOIN mjesto ON pbrStan = pbr
LEFT JOIN zupanija ON mjesto.sifZupanija = zupanija.sifZupanija;


SELECT
	kratPred,
    nazPred,
    pred.sifOrgjed,
    nazOrgjed
FROM pred
LEFT JOIN orgjed ON pred.sifOrgjed = orgjed.sifOrgjed
WHERE nazPred LIKE "F%";


SELECT
	kratPred,
    nazPred,
    pred.sifOrgjed,
    nazOrgjed
FROM pred
LEFT JOIN orgjed ON pred.sifOrgjed = orgjed.sifOrgjed
WHERE nazOrgjed LIKE "Z%";


ROLLBACK WORK;