#include <stdio.h>
#include <ctype.h>
#include <malloc.h>

void bu_sort(int *, int);


int main() {
	char tem[8] = "0";
	bool isnum = true;
	int *nums;
	int total = 0;

	nums = (int *)malloc(sizeof(int));

	while (1) {
		scanf_s("%s", tem, 8);

		for (int i = 0; tem[i] != '\0'; i++)
			if (!isdigit(tem[i]))
				isnum = false;

		if (isnum == false)
			break;
		else
			sscanf(tem, "%d", nums + (total++));

		nums = (int *)realloc(nums, sizeof(int)*(total + 1));
	}

	bu_sort(nums, total);

	for (int i = 0; i < total; i++) {
		printf("%d\n", nums[i]);
	}
	free(nums);
}

void bu_sort(int *nums, int total) {
	for (int i = 0; i < total; i++)
		for (int j = 0; j < total - i; j++) {
			if (nums[j] < +nums[j + 1]) {
				int tem = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = tem;
			}
		}
}
