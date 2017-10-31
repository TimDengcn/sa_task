#include <stdio.h>
#include <malloc.h>
/* 科协Task5提升题目，对结构体排序
 * 默认按id排名
 * */
typedef struct Struct {
    int id;
    double grades;
}Student;


//交换两个对象的位置
void swapint(Student *numa, Student *numb) {
    Student tem;
    tem = *numa;
    *numa = *numb;
    *numb = tem;
}
//对对象进行排序
void bu_sort(Student *nums, int total) {
    int last, i;
    int lows = 0;
    int high = total - 1;
    last = lows;

    //*************************

    while (lows < high) {
        //正向冒泡
        for (i = lows; i < high; i++) {
            if ((nums + i)->id > (nums + i + 1)->id) {
                swapint(nums + i, nums + i + 1);
                last = i;
            }
        }

        high = last;
        //逆向冒泡
        for (i = high; i > lows; i--) {
            if ((nums + i)->id < (nums + i - 1)->id) {
                swapint(nums + i, nums + i - 1);
                last = i;
            }
        }

        lows = last;
    }

}

int main(){
    Student *students;
//分配内存空间
    students=(Student *)malloc(sizeof(Student));
//输入数据，当输入0 0是认为数据输入结束
    int i=0;
    printf("please key in the id&grades of studens(a pair in one line),if want to exit please key in \"0  0\"\n");
    scanf("%d%lf",&students->id,&students->grades);
    while((students+i)->id!=0 && (students+i)->grades!=0){
        i++;
        students=realloc(students,sizeof(Student)*(i+1));
        scanf("%d%lf",&(students+i)->id,&(students+i)->grades);
    }

    int num=i;
//对输入的数据进行排序，按id进行降序排序
    bu_sort(students,num);
//将排完序的的数据进行输出
    printf("\n*****************************\n");
    for(int i=0;i<num;i++){
        printf("ID: %d  Grade: %lf",(students+i)->id,(students+i)->grades);
        printf("\n");
    }
    printf("*****************************\n");
//释放内存空间
    free(students);
    getchar();
    getchar();
    return 0;
}

