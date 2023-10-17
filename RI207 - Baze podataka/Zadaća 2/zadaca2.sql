SELECT sifNastavnik, imeNastavnik, prezNastavnik, koef FROM nastavnik;
SELECT * FROM pred;
SELECT DISTINCT imestud FROM stud;
SELECT DISTINCT sifNastavnik FROM ispit WHERE sifpred = 146 AND ocjena = 1;
SELECT mbrstud FROM ispit WHERE sifpred = 262 AND ocjena > 1;
SELECT preznastavnik, imenastavnik, 800 * ( koef + 0.4 ) as Plata FROM nastavnik;
SELECT preznastavnik FROM nastavnik
WHERE 800 * ( koef + 0.4 ) BETWEEN 3500 AND 8000;
SELECT prezNastavnik, SUBSTRING(imeNastavnik,1,1) AS prvoSlovoImena FROM nastavnik;
SELECT imestud, prezstud, CONCAT(SUBSTRING(imestud, 1, 1), '.', SUBSTRING(prezstud, 1, 1), '.') AS inicijali FROM stud;
SELECT * FROM ispit WHERE MONTH(datIspit) = 7;
SELECT * FROM ispit
WHERE WEEKDAY(datIspit) = 2 AND MONTH(datIspit) = 8;
SELECT mbrStud, ocjena, datIspit, CURDATE() AS trenutniDatum, DATEDIFF(CURRENT_DATE, datIspit) AS ispitBioPrije FROM ispit;
SELECT * FROM stud WHERE datRodStud = DATE_ADD(datRodStud, INTERVAL -30 YEAR);
SELECT sifNastavnik, mbrStud, ocjena, STR_TO_DATE('1,1,2009','%d,%m,%Y') - datIspit AS protekloVrijeme FROM ispit;
SELECT 
	mbrStud,
	sifPred,
    ocjena,
    DATE_ADD(datIspit, INTERVAL 4800 DAY) AS datum
FROM ispit 
WHERE DATE_ADD(datIspit, INTERVAL 4800 DAY) >= CURRENT_DATE;
SELECT mbrStud, sifPred, ocjena, datIspit, ADDDATE(datIspit, INTERVAL 3 YEAR) AS datumTriGodineOdOdrzavanja FROM ispit;
SELECT oznDvorana, oznVrstaDan, sat, sifPred AS predmet FROM rezervacija;
SELECT DISTINCT pbrrod, pbrstan FROM stud;