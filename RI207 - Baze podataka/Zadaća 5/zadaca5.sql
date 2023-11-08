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
WHERE DATE_ADD(datRodStud, INTERVAL -200 DAY) >= (SELECT MIN(datRodStud) FROM stud);

SELECT * FROM pred WHERE sifOrgjed IN
(SELECT sifOrgjed FROM nastavnik WHERE prezNastavnik LIKE 'O%'); 

SELECT oznDvorana, kapacitet FROM dvorana
WHERE kapacitet > (
SELECT COUNT(sifPred) FROM rezervacija WHERE oznDvorana = dvorana.oznDvorana); 

SELECT sifnastavnik, imenastavnik, preznastavnik, koef, nazmjesto
FROM nastavnik INNER JOIN mjesto ON nastavnik.pbrstan = mjesto.pbr
WHERE koef < (
SELECT AVG(koef) FROM nastavnik Ostali INNER JOIN mjesto DrugoM ON
Ostali.pbrstan = DrugoM.pbr
WHERE mjesto.sifZupanija=DrugoM.sifZupanija
AND Ostali.sifNastavnik<>nastavnik.sifNastavnik); 

SELECT mbrstud, imestud, prezstud FROM stud
WHERE NOT EXISTS (
SELECT * FROM ispit WHERE ispit.mbrstud = stud.mbrstud AND
WEEKDAY(ispit.datispit) = WEEKDAY(stud.datrodstud)); 

SELECT sifNastavnik, imeNastavnik, prezNastavnik
FROM nastavnik INNER JOIN mjesto ON nastavnik.pbrStan = mjesto.pbr
INNER JOIN zupanija ON mjesto.sifzupanija = zupanija.sifzupanija
WHERE nazzupanija = "Dubrovačko-neretvanska"
AND koef > ANY (
SELECT koef FROM nastavnik INNER JOIN mjesto ON nastavnik.pbrStan = mjesto.pbr
INNER JOIN zupanija ON mjesto.sifzupanija = zupanija.sifzupanija
WHERE nazzupanija = "Splitsko-dalmatinska"); 

SELECT ispit.mbrstud, imestud, prezstud
FROM ispit INNER JOIN stud ON ispit.mbrstud = stud.mbrstud
WHERE ocjena > 1
AND NOT EXISTS (SELECT * FROM ispit ispitP
WHERE ispitP.sifNastavnik = ispit.sifNastavnik AND ocjena > 1
AND ispit.mbrStud <> ispitP.mbrStud); 

