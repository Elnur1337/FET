#include <iostream>
#include "getAvgRating.h"

using namespace std;

void getAvgRating(const vector<Book>& v) {
	int numberOfBooks = v.size();
	if (numberOfBooks == 0) {
		cout << "Nema unesenih knjiga!" << endl;
		return;
	}
	float ratingSum = 0;
	for (const Book& b : v) {
		ratingSum += b.getRating();
	}
	float avgRating = ratingSum / numberOfBooks;
	cout << "Prosjecna ocjena iznosi: " << avgRating << endl;
	return;
}