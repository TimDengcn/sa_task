#include <stdio.h>

//this program is used to get a 2-d array and transpose it


void bu_sort(int *, int);
void swapint(int *, int *);

int main(void) {
	int rows = 0;
	int lines = 0;

	printf("please entry the rows and lines :\n");
	scanf("%d%d", &rows, &lines);

	int arr[rows][lines];

	printf("please entry the element of the array :\n");

	//entry the keys of arr

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < lines; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	printf("\norigin arr :\n");

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < lines; j++) {
			printf("%d	", arr[i][j]);
		}
		printf("\n");
	}

	printf("\nafter transposition :\n");

	//transposition

	for (int i = 0; i < rows / 2; i++) {
		for (int j = 0; j < lines; j++) {
			int tem = arr[i][j];
			arr[i][j] = arr[rows - 1 - i][lines - 1 - j];
			arr[rows - 1 - i][lines - 1 - j] = tem;
		}
	}

	if (rows % 2 == 1) {
		int i = rows / 2;
		for (int j = 0; j < lines / 2; j++) {
			int tem = arr[i][j];
			arr[i][j] = arr[rows - 1 - i][lines - 1 - j];
			arr[rows - 1 - i][lines - 1 - j] = tem;
		}
	}


	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < lines; j++) {
			printf("%d	", arr[i][j]);
		}
		printf("\n");
	}




	int total[rows*lines];

	//2D into 1D

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < lines; j++) {
			total[i*lines + j] = arr[i][j];
		}
	}

	bu_sort(total, rows*lines);
	//1D into 2D
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < lines; j++) {
			arr[i][j] = total[i*lines + j];
		}
	}



	printf("\nafter being sorted :\n");

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < lines; j++) {
			printf("%d	", arr[i][j]);
		}
		printf("\n");
	}
	getchar();
	getchar();
}

void bu_sort(int *nums, int total) {
	int last, i;
	int lows = 0;
	int high = total - 1;
	last = lows;

	while (lows < high) {
		for (i = lows; i < high; i++) {
			if (*(nums + i) < *(nums + i + 1)) {
				swapint(nums + i, nums + i + 1);
				last = i;
			}
		}

		high = last;
		for (i = high; i > lows; i--) {
			if (*(nums + i) > *(nums + i - 1)) {
				swapint(nums + i, nums + i - 1);
				last = i;
			}
		}

		lows = last;
	}

}

void swapint(int *numa, int *numb) {
	int tem = 0;
	tem = *numa;
	*numa = *numb;
	*numb = tem;
}
