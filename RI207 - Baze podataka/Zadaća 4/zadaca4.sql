SELECT
	CONCAT(SUBSTRING(stud.imeStud, 1, 1), ". ", stud.prezStud) AS "I. Prezime",
    SUBSTRING(pred.nazPred, 1, 25) AS "Naziv predmeta",
    ispit.datIspit AS "Datum ispita"
FROM stud
JOIN ispit ON stud.mbrStud = ispit.mbrStud
JOIN pred ON ispit.sifPred = pred.sifPred
WHERE ispit.ocjena = 5;

SELECT DISTINCT
	orgjed.sifOrgjed AS "Sifra",
    orgjed.NazOrgjed AS "Naziv"
FROM orgjed
JOIN orgjed AS podOrgjed ON orgjed.sifOrgjed = podOrgjed.sifOrgjed
WHERE podOrgjed.nazOrgjed LIKE "%matem%";

SELECT
	pred.nazPred AS "Naziv predmeta",
    pred.kratPred AS "Kratica predmeta"
FROM pred
JOIN orgjed ON pred.sifOrgjed = orgjed.sifOrgjed
JOIN orgjed AS nadOrgjed ON nadOrgjed.sifOrgjed = orgjed.sifNadorgjed
WHERE nadOrgjed.nazOrgjed LIKE "%tehnike%";

SELECT DISTINCT orgjed.nazOrgjed AS "Naziv orgJed"
FROM orgjed
JOIN pred ON orgjed.sifOrgjed = pred.sifOrgjed
JOIN ispit ON pred.sifPred = ispit.sifPred
JOIN nastavnik ON ispit.sifNastavnik = nastavnik.sifNastavnik
JOIN mjesto ON nastavnik.pbrStan = mjesto.pbr
JOIN zupanija ON mjesto.sifZupanija = zupanija.sifZupanija
WHERE 
	nazZupanija = "Dubrovačko-neretvanska"
    AND
    YEAR(ispit.datIspit) = 2000
    AND
    MONTH(ispit.datIspit) = 4;
    
SELECT DISTINCT stud.* FROM stud
JOIN ispit ON stud.mbrStud = ispit.mbrStud
JOIN nastavnik ON ispit.sifNastavnik = nastavnik.sifNastavnik
JOIN mjesto ON nastavnik.pbrStan = mjesto.pbr
JOIN zupanija ON mjesto.sifZupanija = zupanija.sifZupanija
WHERE
	ispit.ocjena = 1
    AND
    zupanija.nazZupanija = "Osječko-baranjska";
    
SELECT
	SUM(upisanoStud) AS "Ukupni broj studenata"
FROM pred
JOIN orgjed ON pred.sifOrgjed = orgjed.sifOrgjed
JOIN orgjed AS nadOrgjed ON orgjed.sifNadorgjed = nadOrgjed.sifOrgjed
WHERE nadOrgjed.nazOrgjed = "Fakultet elektrotehnike i računarstva";

SELECT
	nastavnik.imeNastavnik,
    nastavnik.prezNastavnik,
    orgjed.nazOrgjed
FROM nastavnik
JOIN orgjed ON nastavnik.sifOrgjed = orgjed.sifOrgjed;

SELECT
	stud.imeStud AS "Ime studenta",
    stud.prezStud AS "Prez studenta",
    mjestoStan.nazMjesto AS "Mjesto stanovanja",
    mjestoRod.nazMjesto AS "Mjesto rodjenja",
    zupanija.nazZupanija AS "Naziv zupanije"
FROM stud
JOIN mjesto AS mjestoStan ON stud.pbrStan = mjestoStan.pbr
JOIN mjesto AS mjestoRod ON stud.pbrRod = mjestoRod.pbr
JOIN zupanija ON mjestoRod.sifZupanija = zupanija.sifZupanija;

SELECT
	COUNT(ispit.ocjena) AS "Broj negativnih ocjena"
FROM ispit
JOIN nastavnik ON ispit.sifNastavnik = nastavnik.sifNastavnik
JOIN mjesto ON nastavnik.pbrStan = mjesto.pbr
WHERE 
	mjesto.nazMjesto LIKE "Z%"
    AND
    ispit.ocjena = 1;
    
SELECT
	dvorana.oznDvorana,
    dvorana.kapacitet
FROM dvorana
JOIN rezervacija ON dvorana.oznDvorana = rezervacija.oznDvorana
JOIN pred ON rezervacija.sifPred = pred.sifPred
WHERE
	nazPred = "Energetska elektronika-izabrana poglavlja"
    AND
    (rezervacija.oznVrstaDan = "PO" OR rezervacija.oznVrstaDan = "SR" OR rezervacija.oznVrstaDan = "PE");
    
SELECT DISTINCT orgjed.nazOrgjed
FROM orgjed
JOIN nastavnik ON orgjed.sifOrgjed = nastavnik.sifOrgjed;

SELECT COUNT(DISTINCT(pred.sifPred))
FROM pred
JOIN rezervacija ON pred.sifPred = rezervacija.sifPred
JOIN dvorana ON rezervacija.oznDvorana = dvorana.oznDvorana
WHERE dvorana.kapacitet <= 60;

SELECT DISTINCT mjesto.nazMjesto
FROM mjesto
JOIN stud ON mjesto.pbr = stud.pbrStan
WHERE stud.pbrStan = stud.pbrRod;

SELECT
	stud.imeStud,
    stud.prezStud
FROM stud
JOIN mjesto AS mjestoRod ON stud.pbrRod = mjestoRod.pbr
JOIN mjesto AS mjestoStan ON stud.pbrStan = mjestoStan.pbr
JOIN ispit ON stud.mbrStud = ispit.mbrStud
JOIN pred ON ispit.sifPred = pred.sifPred
WHERE
	pred.nazPred = "Elektronički sklopovi"
    AND
    ispit.ocjena > 1;
    
SELECT stud.* FROM stud
JOIN mjesto AS mjestoStan ON stud.pbrStan = mjestoStan.pbr
JOIN mjesto AS mjestoRod ON stud.pbrRod = mjestoRod.pbr
WHERE
	stud.pbrRod != stud.pbrStan
    AND
    mjestoRod.sifZupanija = mjestoStan.sifZupanija;
    
SELECT DISTINCT nastavnik.* FROM nastavnik
JOIN ispit ON nastavnik.sifNastavnik = ispit.sifNastavnik
JOIN stud ON ispit.mbrStud = stud.mbrStud
WHERE nastavnik.pbrStan = stud.pbrStan;

SELECT
	CONCAT(stud.imeStud, " ", stud.prezStud) AS homePlayer,
    CONCAT(guestStud.imeStud, " ", guestStud.prezStud) AS guestPlayer
FROM stud
JOIN stud AS guestStud
WHERE
	stud.imeStud LIKE "K%"
	AND
    stud.prezStud LIKE "K%"
    AND
    guestStud.imeStud LIKE "K%"
    AND
    guestStud.prezStud LIKE "K%"
    AND
    CONCAT(stud.imeStud, " ", stud.prezStud) != CONCAT(guestStud.imeStud, " ", guestStud.prezStud);
    