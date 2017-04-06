#include <stdio.h>

int main(int argc, char const *argv[]) {
	
	FILE *file;

	int arrangementA[4][4];
	int arrangementB[4][4];
	int selectedRowNumbers[4];			// Numbers of the selected row on arrangementA.
	int matches = 0;					// How many times the number in the arrangementA shows up in arrangementB in a specific row.
	int tests = 0;						// Number of tests.
	int selectedRow1, selectedRow2;		// Volunteer's selected rows.
	int t = 0, i = 0, k = 0;			// Counter.
	int matchKIndex = -1;				// Index [k] of the matched number.
	
	char filepath[] = "/Users/Lucas/Documents/Ciência da Computação/Google Code Jam/A-small-practice.in.txt";

	// Reading the  file.in
	file = fopen(filepath, "r");

	if (!file) return 1;

	// Number of tests
	fscanf(file, "%d", &tests);

	for (t = 1; t <= tests; t++) {

	// First selected row
	fscanf(file, "%d", &selectedRow1);
	
	// Decrement because indexes are [0..3] and the problem says [1..4]
	selectedRow1--;

	// Arrangement A
	for (i = 0; i < 4; i++) {
		for (k = 0; k < 4; k++) {
			fscanf(file, "%d", &arrangementA[i][k]);
		}
	}

	// Numbers of the selected row = all number in the selected row
	for (i = 0; i < 4; i++) {
		selectedRowNumbers[i] = arrangementA[selectedRow1][i];
	}

	// Second selected row
	fscanf(file, "%d", &selectedRow2);

	// Decrement because indexes are [0..3] and the problem says [1..4]
	selectedRow2--;

	// Arrangement B
	for (i = 0; i < 4; i++) {
		for (k = 0; k < 4; k++) {
			fscanf(file, "%d", &arrangementB[i][k]);
		}
	}

	/*
		 Intersec between selectedRow and newSelectedRow.
		 If the numbers on the previous selected row matches only one number in the new selected row, we found the number.
		 If the numbers matches more than once, bad magician.
		 If the numbers are not on the new selected row, volunteer is cheating.
	*/
	for (i = 0; i < 4; i++) {
		for (k = 0; k < 4; k++) {
			if(selectedRowNumbers[i] == arrangementB[selectedRow2][k]) {
				matches++;
				matchKIndex = k;
			}
		}
	}

	// Final test
	if (matches == 1) {
		printf("Your card is %d \n", arrangementB[selectedRow2][matchKIndex]);
	} else if (matches > 1) {
		printf("Bad magician\n");
	} else {
		printf("Volunteer cheating\n");
	}

	// Setting those vars to their initial value so they can be used properly in the next test.
	matches = 0;
	matchKIndex = -1;
}

	fclose(file);
	
	return 0;
}