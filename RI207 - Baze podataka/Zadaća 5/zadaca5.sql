SELECT * FROM stud
WHERE mbrStud NOT IN (SELECT mbrStud FROM ispit WHERE ocjena = 1);

SELECT nazMjesto FROM mjesto
WHERE
	pbr IN (SELECT pbrStan FROM nastavnik)
    AND
    pbr NOT IN (SELECT pbrRod FROM stud);
    
SELECT nazZupanija FROM zupanija
WHERE
	sifZupanija NOT IN (SELECT sifZupanija FROM mjesto JOIN stud ON mjesto.pbr = stud.pbrStan)
    AND
    sifZupanija IN (SELECT sifZupanija FROM mjesto JOIN stud ON mjesto.pbr = stud.pbrRod);

SELECT sifNastavnik, imeNastavnik, prezNastavnik FROM nastavnik
WHERE
	sifNastavnik NOT IN (SELECT sifNastavnik FROM ispit
													WHERE
														ocjena > 1
                                                        AND
                                                        YEAR(datIspit) = YEAR(NOW())
                                                        AND
                                                        (MONTHNAME(datIspit) = "January" OR MONTHNAME(datIspit) = "February"));
                                                        
SELECT imeStud, prezStud, datRodStud FROM stud
WHERE DATE_ADD(datRodStud, INTERVAL 200 DAY) <= (SELECT MAX(datRodStud) FROM stud);

SELECT * FROM pred
WHERE
	sifOrgjed IN (SELECT DISTINCT sifOrgjed FROM nastavnik WHERE prezNastavnik LIKE "O%");
    
SELECT * FROM dvorana WHERE kapacitet > (SELECT COUNT(sifPred) FROM rezervacija WHERE oznDvorana = dvorana.oznDvorana);

SELECT
	nastavnik.sifNastavnik,
    nastavnik.imeNastavnik,
    nastavnik.prezNastavnik,
    nastavnik.koef,
    mjesto.nazMjesto
FROM nastavnik
JOIN mjesto ON nastavnik.pbrStan = mjesto.pbr
WHERE koef < (SELECT AVG(koef) FROM nastavnik
			  JOIN mjesto AS mjesto2 ON nastavnik.pbrStan = mjesto2.pbr
              WHERE mjesto.sifZupanija = mjesto2.sifZupanija
			 );
             
SELECT
	stud.mbrStud,
    stud.imeStud,
    stud.prezStud
FROM stud
WHERE DAYNAME(stud.datRodStud) NOT IN (SELECT DAYNAME(ispit.datIspit) FROM ispit WHERE ispit.mbrStud = stud.mbrStud);

SELECT 
	nastavnik.sifNastavnik,
    nastavnik.imeNastavnik,
    nastavnik.prezNastavnik
FROM nastavnik
JOIN mjesto ON nastavnik.pbrStan = mjesto.pbr
JOIN zupanija ON mjesto.sifZupanija = zupanija.sifZupanija
WHERE
	zupanija.nazZupanija = "Dubrovačko-neretvanska"
    AND
    nastavnik.koef > ANY (SELECT nastavnik.koef FROM nastavnik
						  JOIN mjesto ON nastavnik.pbrStan = mjesto.pbr
                          JOIN zupanija ON mjesto.sifZupanija = zupanija.sifZupanija
                          WHERE zupanija.nazZupanija = "Splitsko-dalmatinska");

SELECT
	stud.mbrStud,
    stud.imeStud,
    stud.prezStud
FROM stud
JOIN ispit ON stud.mbrStud = ispit.mbrStud
WHERE
	ispit.ocjena > 1
    AND
    ispit.sifNastavnik NOT IN (SELECT sifNastavnik FROM ispit WHERE ocjena > 1 AND mbrStud != stud.mbrStud);