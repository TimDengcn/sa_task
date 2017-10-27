#include <stdio.h>
#include <malloc.h>
#include <ctype.h>
/*此函数用于反转输入的整数*/
void rever(void){
    long long numin;
    scanf("%lld",&numin);
    int leng=0;
    int *apart_num=(int *)malloc(sizeof(int));
    apart_num[leng]=numin%10;
    //用于分离出各个数位的数
    while(apart_num[leng]!=numin){
        leng++;
        apart_num=(int*)realloc(apart_num,sizeof(int)*(leng+1));
        numin=(numin-apart_num[leng-1])/10;
        apart_num[leng]=numin%10;
    }
    int tens=1;
    long long numout=0;
    //将各个数位的数按照相反的权重再加在一起
    for(int n=leng;n>=0;n--){
        numout+= apart_num[n]*tens;
        tens*=10;
    }
    printf("%lld",numout);
}
/*从字符串中找整数,使用了strtol函数 XD*/
void int_select(void){
    long *num_long=(long *)malloc(sizeof(long));
    char sen_tem[100];
    int num_total=0;
    char *end_ptr;
    gets(sen_tem);
    num_long[num_total] = strtol(sen_tem,&end_ptr,10);
    if(isdigit(*(end_ptr-1))){
        num_total++;
        num_long=(long *)realloc(num_long,sizeof(long)*(num_total+1));
    }
    while(*end_ptr!='\0'){
        num_long[num_total] = strtol(end_ptr+1,&end_ptr,10);
        //用于判断返回是因为找到了整数还是因为是连续的字符串，找浮点数中同理。
        if(isdigit(*(end_ptr-1))){
            num_total++;
            num_long=(long *)realloc(num_long,sizeof(long)*(num_total+1));
        }
    }
    for(int i=0;i<num_total;i++){
        printf("%ld   ",num_long[i]);
    }
}
/*从字符串中找浮点数,使用了strtod函数 XD*/
void float_select(void){

    double *num_double=(double *)malloc(sizeof(double));
    char sen_tem[100];
    int num_total=0;
    char *end_ptr;
    gets(sen_tem);
    num_double[num_total] = strtod(sen_tem,&end_ptr);
    if(isdigit(*(end_ptr-1))){
        num_total++;
        num_double=(double *)realloc(num_double,sizeof(double)*(num_total+1));
    }
    while(*end_ptr!='\0'){
        num_double[num_total] = strtod(end_ptr+1,&end_ptr);
        if(isdigit(*(end_ptr-1))){
            num_total++;
            num_double=(double *)realloc(num_double,sizeof(double)*(num_total+1));
        }
    }
    for(int i=0;i<num_total;i++){
        printf("%lf   ",num_double[i]);
    }
}

int main() {
    while(1) {
      /*貌似三个都打开的话好像在输入缓存上会有一点问题*/
        /****************倒置整数*****************/
        //rever();
        /****************选出整数*****************/
        //int_select();
        /***************选出浮点数****************/
        //float_select();
        putchar('\n');
    }
    return 0;
}
