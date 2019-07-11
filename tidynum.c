#include <stdio.h>

int main() {

	int tests, i, k;
	int n;
	int last = 0;
	int num = 0;
	int temp1 = 0, temp2 = 0;
	int tidy = 0;

	scanf("%d", &tests);

	for (i = 0; i < tests; i++) {
		scanf("%d", &n);

		if (n < 10) {
			last = n;
			printf("Case #%d: %d\n", i+1, last);
			continue;
		}

		num = 1;
		last = num;
		while (num <= n) {

			for(k = num; k; k/=10) {
				tidy = 0;
				temp1 = k % 10;

				if (k == num) {
					temp2 = temp1;
					tidy = 1;
					continue;
				}
				
				if (temp1 <= temp2) {
					temp2 = temp1;
					tidy = 1;
					continue;
				} else {
					tidy = 0;
					break;
				}	
			}

			if (tidy != 0){
				last = num;
			}
			num++;
		}

	printf("Case #%d: %d\n", i+1, last);
	}

 return 0;
}