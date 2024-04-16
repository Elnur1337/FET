package paket;

import java.util.ArrayList;

public class MagicniKvadrat implements Comparable<MagicniKvadrat> {
	private ArrayList<ArrayList<Integer>> v;
	
	public MagicniKvadrat() {
		v = new ArrayList<ArrayList<Integer>>();
	}
	
	public void ucitajRed(String rowString) {
		if (rowString.length() == 0) {
			return;
		}
		ArrayList<Integer> red = new ArrayList<Integer>();
		String[] stringArr = rowString.split("\t");
		Integer e;
		for (String eString : stringArr) {
			try {
				e = Integer.parseInt(eString);
				red.add(e);
			} catch (NumberFormatException e2) {
				System.out.println("Neki od elemenata u redu nisu brojevi!");
				e2.printStackTrace();
				return;
			}
		}
		v.add(red);
		return;
	}
	
	public boolean provjeriMagicnost() {
		for (int i = 0; i < v.size(); ++i) {
			if (v.size() != v.get(i).size()) {
				return false;
			}
		}
		int sum = 0;
		int currentSum = 0;
		for (int i = 0; i < v.size(); ++i) {
			currentSum = 0;
			for (int j = 0; j < v.size(); ++j) {
				currentSum += v.get(i).get(j);
				if (i == 0) {
					sum += v.get(i).get(j);
				}
			}
			if (currentSum != sum) {
				return false;
			}
		}
		for (int i = 0; i < v.size(); ++i) {
			currentSum = 0;
			for (int j = 0; j < v.size(); ++j) {
				currentSum += v.get(j).get(i);
			}
			if (currentSum != sum) {
				return false;
			}
		}
		currentSum = 0;
		for (int i = 0; i < v.size(); ++i) {
			currentSum += v.get(i).get(i);
		}
		if (currentSum != sum) {
			return false;
		}
		currentSum = 0;
		for (int i = v.size() - 1; i >= 0; --i) {
			currentSum += v.get(i).get(i);
		}
		if (currentSum != sum) {
			return false;
		}
		return true;
	}
	
	public String toString() {
		return v.toString();
	}
	
	public boolean equals(Object other) {
		if (!(other instanceof MagicniKvadrat)) {
			return false;
		}
		if (!v.equals(other)) {
			return false;
		}
		return true;
	}
	
	public int compareTo(MagicniKvadrat other) {
		if (this.v.size() < other.v.size()) {
			return -1;
		} else if (this.v.size() > other.v.size()) {
			return 1;
		} else {
			return 0;
		}
	}
}
