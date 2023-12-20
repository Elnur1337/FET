SELECT
	mbrStud,
    datPrijava,
	ocjObrane(mbrStud, datPrijava) AS ukupnaOcjena
FROM diplom;

SELECT
	diplom.mbrStud,
    prezStud,
    imeStud,
    ocjObrane(diplom.mbrStud, datPrijava) AS ukupnaOcjena
FROM diplom
JOIN stud ON diplom.mbrStud = stud.mbrStud
WHERE ocjObrane(diplom.mbrStud, datPrijava) > 1;

SELECT AVG(ocjObrane(mbrStud, datPrijava)) FROM diplom
WHERE ocjObrane(mbrStud, datPrijava) > 1;


DELIMITER //
CREATE FUNCTION prosjekOcjena()
RETURNS DECIMAL(3, 2) DETERMINISTIC
BEGIN
	DECLARE prosOc DECIMAL(3, 2);

	IF @counter IS NULL THEN
		SET @counter = 0;
	END IF;
    SET @counter = @counter + 1;
    IF @counter = 1 THEN
		SELECT AVG(ocjena) INTO prosOc FROM ispit WHERE ocjena > 1;
	ELSE
		SET prosOc = NULL;
	END IF;
    RETURN prosOc;
END//

SELECT prosjekOcjena();

DELIMITER //

CREATE FUNCTION brojNepristup()
RETURNS INTEGER DETERMINISTIC
BEGIN
	DECLARE brNep INTEGER;
    
    IF @counter1 IS NULL THEN
		SET @counter1 = 0;
	END IF;
    SET @counter1 = @counter1 + 1;
    IF @counter1 = 1 THEN
		SELECT COUNT(*) INTO brNep FROM stud WHERE mbrStud NOT IN (SELECT DISTINCT mbrStud FROM ispit);
	ELSE
		SET brNep = NULL;
	END IF;
    RETURN brNep;
END//

SELECT brojNepristup();


DELIMITER //
CREATE PROCEDURE vrijemePrvogPoziva()
BEGIN
	IF @timeFirst IS NULL THEN
		SET @timeFirst = NOW();
	END IF;
    SELECT 
		NOW() AS trenutnoVrijeme,
        @timeFirst AS vrijemePrvogPoziva;
END//

CALL vrijemePrvogPoziva();


DELIMITER //
CREATE PROCEDURE najboljih_n(n INTEGER)
BEGIN
	
END//