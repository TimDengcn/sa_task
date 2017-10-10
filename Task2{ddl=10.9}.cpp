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

	//����Ƿ�Ϊ����,�����������,����������ѭ��

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

	printf("\n\n��Ϊ�������:\n");

	for (int i = 0; i < total; i++) {
		printf("%d	", nums[i]);
	}

	rever(nums, total);

	printf("\n\n��Ϊ���ú���:\n");

	for (int i = 0; i < total; i++) {
		printf("%d	", nums[i]);
	}

	//*************************

	free(nums);
}


//����ð��+��ǰ��ֹ+��¼���λ���Լ���������

void bu_sort(int *nums, int total) {
	int last, i;
	int lows = 0;
	int high = total - 1;
	last = lows;

	//*************************

	while (lows < high) {
		//����ð��
		for (i = lows; i < high; i++) {
			if (*(nums + i) > *(nums + i + 1)) {
				swapint(nums + i, nums + i + 1);
				last = i;
			}
		}

		high = last;
		//����ð��
		for (i = high; i > lows; i--) {
			if (*(nums + i) < *(nums + i - 1)) {
				swapint(nums + i, nums + i - 1);
				last = i;
			}
		}

		lows = last;
	}

}

//����

void swapint(int *numa, int *numb) {
	int tem = 0;
	tem = *numa;
	*numa = *numb;
	*numb = tem;
}

//����

void rever(int * nums, int total) {
	for (int i = 0; i < total / 2; i++) {
		int tem = *(nums + i);
		*(nums + i) = *(nums + total - 1 - i);
		*(nums + total - 1 - i) = tem;
	}
}