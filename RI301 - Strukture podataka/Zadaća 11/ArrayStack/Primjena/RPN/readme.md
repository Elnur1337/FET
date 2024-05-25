# RPN kalkulator

Potrebno je implementirati Postfix (Reverse Polish Notation - RPN) kalkulator koristeći Stack kontejner koji je prethodno implementiran. 
Kalkulator će se koristiti za evaluaciju matematičkih izraza u Postfix notaciji.

Postfix notacija je jedna od formi zapisa matematičkih izraza u kojoj se operatori pišu nakon operanada. 
Na primjer, izraz "3 + 4" u Postfix notaciji bi bio zapisan kao "3 4 +". 
Kada se izračunava izraz u Postfix notaciji, operandi se stavljaju na stack, 
a zatim se operatori primjenjuju na operande s vrha stack-a.
Nakon izvršene operacije, rezultat se ponovo dodaje na stack.
Neophodno je implementirati main() funkciju koja testira funkcionalnost RPN kalkulatora.
