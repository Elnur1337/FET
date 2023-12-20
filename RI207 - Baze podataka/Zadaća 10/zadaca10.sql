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