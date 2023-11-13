SELECT
	pred.kratPred,
	pred.nazPred,
    AVG(ispit.ocjena)
FROM ispit
JOIN pred ON ispit.sifPred = pred.sifPred
WHERE ispit.ocjena > 1
GROUP BY ispit.sifPred;

SELECT
	zupanija.sifZupanija,
	COUNT(ispit.ocjena)
FROM ispit
JOIN nastavnik ON ispit.sifNastavnik = nastavnik.sifNastavnik
JOIN mjesto ON nastavnik.pbrStan = mjesto.pbr
JOIN zupanija ON mjesto.sifZupanija = zupanija.sifZupanija
WHERE ispit.ocjena = 1
GROUP BY zupanija.sifZupanija;

SELECT
	nastavnik.imeNastavnik,
    COUNT(ispit.ocjena)
FROM nastavnik
JOIN ispit ON nastavnik.sifNastavnik = ispit.sifNastavnik
WHERE ispit.ocjena > 1
GROUP BY nastavnik.sifNastavnik;

SELECT
	orgjed.sifOrgjed,
    orgjed.nazOrgjed,
    COUNT(orgjedP.sifOrgjed)
FROM orgjed
JOIN orgjed AS orgjedP ON orgjed.sifOrgjed = orgjedP.sifNadorgjed
GROUP BY orgjed.sifOrgjed;

SELECT 
	stud.*,
    ((SELECT AVG(ocjena) FROM ispit WHERE mbrStud = stud.mbrStud AND ocjena > 1))
FROM stud
JOIN ispit ON stud.mbrStud = ispit.mbrStud
WHERE (SELECT AVG(ocjena) FROM ispit WHERE mbrStud = stud.mbrStud AND ocjena > 1) > 3
GROUP BY stud.mbrStud;

SELECT
	mjesto.pbr,
    mjesto.nazMjesto,
    COUNT(stud.mbrStud)
FROM mjesto
JOIN stud ON mjesto.pbr = stud.pbrRod
WHERE (SELECT COUNT(pbrRod) FROM stud WHERE pbrRod = mjesto.pbr) > 5
GROUP BY mjesto.pbr;

SELECT
	ispit.mbrStud,
    stud.prezStud,
    CONCAT(SUBSTRING(stud.prezStud, 1, 1), '.', SUBSTRING(stud.imeStud, 1, 1), '.') AS inicijali
FROM ispit
JOIN stud ON ispit.mbrStud = stud.mbrStud
WHERE ocjena = 1
GROUP BY 1, ispit.sifPred
HAVING COUNT(ispit.ocjena) > 2;

SELECT
	mbrStud,
    ocjena
FROM ispit
GROUP BY 1, 2
HAVING COUNT(DISTINCT datIspit) > 1;

SELECT
	pbr,
    sifZupanija
FROM mjesto
GROUP BY 1, 2
HAVING COUNT(DISTINCT nazMjesto) > 1;

SELECT
	imeNastavnik
FROM nastavnik
GROUP BY 1
HAVING COUNT(DISTINCT prezNastavnik) > 1;

SELECT
	sifPred,
    datIspit,
    ocjena
FROM ispit
GROUP BY 1, 2, 3
HAVING COUNT(distinct mbrStud) > 1;

SELECT
	sifPred,
    datIspit,
    ocjena
FROM ispit
GROUP BY 1, 2, 3
HAVING COUNT(distinct sifNastavnik) > 1;

SELECT
	mjesto.pbr,
    mjesto.nazMjesto,
    (SELECT COUNT(ispit.ocjena) FROM ispit JOIN stud ON ispit.mbrStud = stud.mbrStud WHERE ocjena > 1 AND stud.pbrStan = mjesto.pbr)
FROM mjesto
WHERE (SELECT COUNT(ispit.ocjena) FROM ispit JOIN stud ON ispit.mbrStud = stud.mbrStud WHERE ocjena > 1 AND stud.pbrStan = mjesto.pbr) > 0
ORDER BY mjesto.nazMjesto;

SELECT
	stud.imeStud,
    stud.prezStud,
    COUNT(ispit.ocjena) AS brojPoIspita
FROM stud
JOIN ispit ON stud.mbrStud = ispit.mbrStud
WHERE ispit.ocjena > 1
GROUP BY ispit.mbrStud
ORDER BY brojPoIspita DESC, stud.prezStud, stud.imeStud;

CREATE TEMPORARY TABLE mjestoTmp AS
SELECT 
	mjesto.*,
    COUNT(nastavnik.sifNastavnik) AS brojNast
FROM mjesto
JOIN nastavnik ON mjesto.pbr = nastavnik.pbrStan
GROUP BY mjesto.pbr;

SELECT * FROM mjestoTmp;

SELECT
	MONTHNAME(datRodStud),
	COUNT(mbrStud)
FROM stud
GROUP BY 1
ORDER BY 2 DESC;

CREATE TEMPORARY TABLE ispitPo AS
SELECT
	mbrStud,
	COUNT(ocjena) AS brPoIspita,
    AVG(ocjena) AS prosOcjena
FROM ispit
GROUP BY mbrStud;

SELECT * FROM ispitPo;

SELECT stud.* FROM stud
JOIN ispit ON stud.mbrStud = ispit.mbrStud
WHERE ocjena > 1
GROUP BY stud.mbrStud
HAVING
(
	AVG(ocjena) > (SELECT AVG(ocjena) FROM ispit WHERE ispit.mbrStud != stud.mbrStud)
	OR
    COUNT(ocjena) > (SELECT AVG(brPoIspita) FROM ispitPo WHERE ispitPo.mbrStud != stud.mbrStud)
);