#include <stdio.h>
#include <malloc.h>

//this program is used to get a 2-d array and transpose it


void bu_sort(int *, int);
void swapint(int *, int *);

int main(void) {
    int rows = 0;
    int lines = 0;

    printf("please entry the rows and lines :\n");
    scanf("%d%d", &rows, &lines);

    int (* arr)[lines]=(int (*)[lines])malloc(sizeof(int)*rows*lines);

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

    int (* traned_arr)[rows]=(int (*)[rows])malloc(sizeof(int)*rows*lines);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < lines; j++) {
            traned_arr[j][i]=arr[i][j];
        }
    }

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d	", traned_arr[i][j]);
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
    free(arr);
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
