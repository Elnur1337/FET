#include "sortTeams.h"
#include "quicksort.h"

void sortTeams(Tim* arr, size_t n) {
	quicksort(arr, n, [](const Tim& t1, const Tim& t2) {
			return t1.naziv < t2.naziv;
		}
	);
	quicksort(arr, n, [](const Tim& t1, const Tim& t2) {
			return t1.postignutiGolovi > t2.postignutiGolovi;
		}
	);
	quicksort(arr, n, [](const Tim& t1, const Tim& t2) {
			return t1.postignutiGolovi - t1.primljeniGolovi > t2.postignutiGolovi - t2.primljeniGolovi;
		}
	);
	quicksort(arr, n, [](const Tim& t1, const Tim& t2) {
			return t1.bodovi < t2.bodovi;
		}
	);
	return;
}
