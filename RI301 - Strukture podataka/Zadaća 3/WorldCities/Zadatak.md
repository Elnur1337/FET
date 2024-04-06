# Zadatak


Napisati C++ program koji čita sadržaj fajla *WorldCities.csv*.
- Prvi red je zaglavlje (Preskočiti prilikom parsiranja)

Fajl se sastoji od sljedećih podataka:
- Ime grada
- Geografska širina
- Geografska dužina
- Država
- Status grada: 
  - *primary* označava glavni grad 
  - *admin* označava status grada koji je po važnosti iza *primary*
  - *minor* označava grad nižeg statusa
- Broj stanovnika
- Identifikator grada 

Neophodno je napisati program koji na pravilan način učitava sve podatke iz fajla. 
Nakon uspješnog učitavanja, omogućiti korisniku pretraživanje na osnovu različitog kriterija:
- Ispisati sve gradove iz željene države sortirane kao:
  - Za prikaz gradova poredanih po broju stanovnika korisnik unosi odgovarajuću komandu
  - Za prikaz gradova poredanih po nazivu korisnik unosi odgovarajuću komandu
- Ispis svih država:
  - Poredanih po ukupnom broju stanovnika
  - Poredanih po nazivu

  Ispis za državu treba da sadrži:
  - Naziv države
  - Glavni grad
  - Najveći grad
  - Ukupan broj stanovnika
  - Broj gradova
- Ispis određenog grada sa svim podacima koji se nalaze u fajlu
- Ispis svih glavnih gradova zajedno sa državom u kojoj se nalaze
- Ispis najvećih gradova sa ukupnim brojem stanovnika, te državom u kojoj se nalaze


Prilikom implementacije programa, neophodno je koristiti različite kontejnere koji omogućavaju optimalno pretraživanje, sortiranje i organizaciju podataka.
Neophodno je osigurati da korisnik konstantno unosi komande za pretraživanje po različitim kriterijima. 
Nazive komandi koje korisnik kreirati po želji te ispisati prilikom pokretanja programa ili kada korisnik unese komandu "help".


