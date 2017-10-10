#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#include <stdbool.h>


void bu_sort(int *, int);
void swapint(int *, int *);
void rever(int *, int);


int main() {
	char tem[10] = "0";
	bool isnum = true;
	int *nums;
	int total = 0;

	//*************************

	nums = (int *)malloc(sizeof(int));

	//检测是否为数字,是则继续输入,不是则跳出循环

	while (1) {
		scanf("%s", tem);

		if (*tem == '-') {
			int i;
			for (i = 1; *(tem + i) != '\0'; i++)
				if (!isdigit(*(tem + i)))
					isnum = false;

			if (i<2)
				isnum = false;

		}
		else {
			int i;
			for (i = 0; *(tem + i) != '\0'; i++)
				if (!isdigit(*(tem + i)))
					isnum = false;

		}

		if (isnum == false)
			break;
		else
			sscanf(tem, "%d", nums + (total++));

		nums = (int *)realloc(nums, sizeof(int)*(total + 1));
	}

	//*************************

	bu_sort(nums, total);

	printf("\n\n此为排序后结果:\n");

	for (int i = 0; i < total; i++) {
		printf("%d	", nums[i]);
	}

	rever(nums, total);

	printf("\n\n此为倒置后结果:\n");

	for (int i = 0; i < total; i++) {
		printf("%d	", nums[i]);
	}

	//*************************

	free(nums);
}


//正反冒泡+提前终止+记录最后位置以减少运算量

void bu_sort(int *nums, int total) {
	int last, i;
	int lows = 0;
	int high = total - 1;
	last = lows;

	//*************************

	while (lows < high) {
		//正向冒泡
		for (i = lows; i < high; i++) {
			if (*(nums + i) > *(nums + i + 1)) {
				swapint(nums + i, nums + i + 1);
				last = i;
			}
		}

		high = last;
		//逆向冒泡
		for (i = high; i > lows; i--) {
			if (*(nums + i) < *(nums + i - 1)) {
				swapint(nums + i, nums + i - 1);
				last = i;
			}
		}

		lows = last;
	}

}

//交换

void swapint(int *numa, int *numb) {
	int tem = 0;
	tem = *numa;
	*numa = *numb;
	*numb = tem;
}

//倒置

void rever(int * nums, int total) {
	for (int i = 0; i < total / 2; i++) {
		int tem = *(nums + i);
		*(nums + i) = *(nums + total - 1 - i);
		*(nums + total - 1 - i) = tem;
	}
}