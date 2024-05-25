# Zadatak 1

Implementirati generički kontejner Stack korištenjem niza. Neophodno je implementirati sve deklarisane metode da bi svi testovi uspješno prošli.
U fajlu main.cpp testirati sve metode te odraditi analogiju sa std::stack kontejnerom.

# Zadatak 2

Potrebno je implementirati Postfix (Reverse Polish Notation - RPN) kalkulator koristeći Stack kontejner koji je prethodno implementiran. 
Kalkulator će se koristiti za evaluaciju matematičkih izraza u Postfix notaciji.

Postfix notacija je jedna od formi zapisa matematičkih izraza u kojoj se operatori pišu nakon operanada. 
Na primjer, izraz "3 + 4" u Postfix notaciji bi bio zapisan kao "3 4 +". 
Kada se izračunava izraz u Postfix notaciji, operandi se stavljaju na stack, 
a zatim se operatori primjenjuju na operande s vrha stack-a.
Nakon izvršene operacije, rezultat se ponovo dodaje na stack.
U main.cpp je dat primjer korištenja ove klase. Neophodno je implementirati sve navedene funkcionalnosti da bi se kod uspješno izvršio.

# Zadatak 3

Napisati program koji provjerava da li je korisnik unio odgovarajući broj otvorenih i zatvorenih zagrada. Program treba u svojoj implementaciji da koristi Stack kontejner koji je implementiran u zadatku 1.
U prilogu je napisan testni program koji definira validan i nevalidan unos korisnika. Zadatak je implementirati funkciju checkBrackets koja vraća true u slučaju da je korisnik unio ispravan broj otvorenih i zatvorenih zagrada, u suprotnom vraća false.

# Zadatak 4

Implementirati Stack kontejner korištenjem povezanih memorijskih lokacija. Svi testovi moraju uspješno proći nakon definicije metoda koji su deklarisani u fajlu Stack.hpp
