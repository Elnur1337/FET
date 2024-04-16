package paket;

//Readers
import java.io.BufferedReader;
import java.io.FileReader;

//Exceptions
import java.io.FileNotFoundException;
import java.io.IOException;

public class Main {

	public static void main(String[] args) {
		MagicniKvadrat kvadrat = new MagicniKvadrat();
		MagicniKvadrat kvadrat2 = new MagicniKvadrat();
		BufferedReader reader;
		try {
			reader = new BufferedReader(new FileReader("./Zad1a.txt"));
		} catch (FileNotFoundException e) {
			System.out.println("Uneseni fajl nije pronadjen!");
			return;
		}
		String row;
		try {
			row = reader.readLine();
			while (row != null) {
				kvadrat.ucitajRed(row);
				row = reader.readLine();
			}
			reader.close();
		} catch (IOException e) {
			System.out.println("Greska u citanju fajla!");
			return;
		}
		if (kvadrat.provjeriMagicnost()) {
			System.out.println("Prvi kvadrat je magican!");
		} else {
			System.out.println("Prvi kvadrat nije magican!");
		}
		
		
		try {
			reader = new BufferedReader(new FileReader("./Zad1b.txt"));
		} catch (FileNotFoundException e) {
			System.out.println("Uneseni fajl nije pronadjen!");
			return;
		}
		try {
			row = reader.readLine();
			while (row != null) {
				kvadrat2.ucitajRed(row);
				row = reader.readLine();
			}
			reader.close();
		} catch (IOException e) {
			System.out.println("Greska u citanju fajla!");
			return;
		}
		if (kvadrat2.provjeriMagicnost()) {
			System.out.println("Drugi kvadrat je magican!");
		} else {
			System.out.println("Drugi kvadrat nije magican!");
		}
	}

}
