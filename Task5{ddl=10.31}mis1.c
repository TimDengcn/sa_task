#include <stdio.h>
#include <stdarg.h>

int suming(int n,...){
    va_list va;
    va_start(va,n);
    int num=0;
    int sum=n;
    do{
        num=va_arg(va,int);
        if(num!=-1024){
            sum+=num;
        }else{
            return sum;
        }
    }while(num!=-1024);

}
int main() {
    int num = suming(100,120,100, -1024,45);
    printf("num = %d\n", num);
    num=getchar();
}

