#include <stdio.h>
#include <malloc.h>

typedef struct oddnumber{
    int *number;
    int total;
}oddnumber;

typedef struct evennumber{
    int *number;
    int total;
}evennumber;

void bu_sort(int *, int);
void swapint(int *, int *);
void putinarray(oddnumber *,evennumber *,int);

int main(){
    int total;
    printf("key in the number of the numbers :");
    scanf("%d",&total);

    oddnumber *oddnumbers=(oddnumber *)malloc(sizeof(oddnumber));
    oddnumbers->total=0;
    oddnumbers->number=(int *)malloc(sizeof(int)*total);
    evennumber *evennumbers=(evennumber *)malloc(sizeof(evennumber));
    evennumbers->total=0;
    evennumbers->number=(int *)malloc(sizeof(int)*total);


    int tempnumber;


    printf("key in the he numbers :\n");

    for(int i=0;i<total;i++){
        scanf("%d",&tempnumber);
        putinarray(oddnumbers,evennumbers,tempnumber);
    }

    bu_sort(oddnumbers->number,oddnumbers->total);
    bu_sort(evennumbers->number,evennumbers->total);

    int *finalnumbers=(int *)malloc(sizeof(int)*total);
    for(int i=0;i<oddnumbers->total;i++){
        *(finalnumbers+i)=*(oddnumbers->number+i);
    }
    for(int i=0;i<evennumbers->total;i++){
        *(finalnumbers+i+oddnumbers->total)=*(evennumbers->number+i);
    }

    printf("the final numbers are :\n");

    for(int i=0;i<total;i++){
        printf("%d\t",*(finalnumbers+i));
    }
    return 0;
}

void putinarray(oddnumber *odds,evennumber *evens,int number){
    if(number%2){
        *(odds->number + odds->total)=number;
        odds->total++;
    }else{
        *(evens->number + evens->total)=number;
        evens->total++;
    }
}

void bu_sort(int *nums, int total) {
    int last, i;
    int lows = 0;
    int high = total-1;
    last = lows;

    while (lows < high) {
        for (i = lows; i < high; i++) {
            if (*(nums + i) > *(nums + i + 1)) {
                swapint(nums + i, nums + i + 1);
                last = i;

            }
        }

        high = last;
        for (i = high; i > lows; i--) {
            if (*(nums + i) < *(nums + i - 1)) {
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