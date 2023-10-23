SELECT DISTINCT sifZupanija FROM mjesto WHERE nazMjesto LIKE "Z%";
SELECT * FROM stud
	WHERE 
		datRodStud BETWEEN '1982-05-01' AND '1982-09-01' 
		AND 
        (prezStud LIKE "R%" OR prezStud LIKE "P%" OR prezStud LIKE "S%" OR prezStud LIKE "V%");
SELECT 
	imeStud,
    prezStud
FROM stud
	WHERE
		datRodStud BETWEEN '1982-05-01' AND '1982-09-01'
        AND
        prezStud RLIKE "^[RPSV]";
SELECT nazMjesto FROM mjesto
	WHERE
		(nazMjesto LIKE 'A%' OR nazMjesto LIKE 'E%' OR nazMjesto LIKE 'I%' OR nazMjesto LIKE 'O%' OR nazMjesto LIKE 'U%')
        AND
        (nazMjesto LIKE '%a' OR nazMjesto LIKE '%e' OR nazMjesto LIKE '%i' OR nazMjesto LIKE '%o' OR nazMjesto LIKE '%u');
SELECT nazMjesto FROM mjesto
	WHERE
    nazMjesto NOT RLIKE '^[AEIOU]' AND nazMjesto NOT RLIKE '[aeiou]$';
SELECT
	imeStud,
    prezStud
FROM stud
	WHERE datRodStud !=
		STR_TO_DATE(
			CONCAT(
				SUBSTRING(jmbgStud, 1, 2),
				'-',
				SUBSTRING(jmbgStud, 3, 2),
				'-',
				IF(SUBSTRING(jmbgStud, 5, 1) > 0, '1', '2'),
				SUBSTRING(jmbgStud, 5, 3)
			),
		'%d-%m-%Y');
SELECT
	AVG(koef) AS prosjecniKoeficijent
FROM nastavnik
	WHERE pbrStan = 10000;
SELECT MIN(datIspit), MAX(datIspit) FROM ispit;
SELECT COUNT(DISTINCT sifOrgjed) FROM nastavnik WHERE pbrStan = 10000; 
SELECT DATEDIFF(MAX(datRodStud), MIN(datRodStud)) FROM stud;
SELECT AVG(ocjena) FROM ispit
	WHERE
		YEAR(datIspit) = 1999
    AND
		ocjena > 1;
SELECT COUNT(sifPred), AVG(ocjena) FROM ispit WHERE sifPred = 146 AND ocjena > 1;
SELECT AVG(DATEDIFF(NOW(), datRodStud)) FROM stud
	WHERE
		pbrRod = 10000
    AND
		imeStud RLIKE '^[AEIOU]'
	AND
		imeStud RLIKE '[aeiou]$';
SELECT COUNT(DISTINCT sifPred) FROM rezervacija
	WHERE
		oznDvorana LIKE 'B%'
	AND
		(oznVrstaDan = 'SR' OR oznVrstaDan = 'UT');
SELECT
	COUNT(mbrStud),
    AVG(ocjena)
FROM ispit
WHERE
	MONTH(datIspit) = 7
AND
	DAYNAME(datIspit) = 'Friday'
AND
	DATE_ADD(datIspit, INTERVAL 5 YEAR) <= NOW();
SELECT SUM(upisanoStud) FROM pred
WHERE
	brojSatiTjedno > 3
AND
	nazPred LIKE '%tehnike%';