SELECT
	mbrStud,
    datPrijava,
	ocjObrane(mbrStud, datPrijava) AS ukupnaOcjena
FROM diplom;