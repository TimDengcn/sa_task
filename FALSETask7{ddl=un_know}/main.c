#include "main.h"

int main(){

    int numberofpeople;
    int firstkey;
    CirList mylist;
    CirNode *nownode;

//初始化链表
    mylist=(CirList)malloc(sizeof(CirNode));
    mylist->number=0;
    mylist->data=0;
    mylist->next=NULL;
    nownode=mylist;   

//输入人数
    printf("key the number of people :");
    scanf("%d",&numberofpeople);

//输入每个人的key，此列表存在列表头
    for(int n=0;n<numberofpeople;n++){
        CirNode *tempnode=(CirNode *)malloc(sizeof(CirNode));
        tempnode->number=n+1;
        scanf("%d",&tempnode->data);
        tempnode->next=NULL;
        nownode->next=tempnode;
        nownode=tempnode;
    }

//输入第一个key
    printf("\nkey the key of the first people :");
    scanf("%d",&firstkey);
    putchar('\n');

//构造链表环
    createCirList(mylist,numberofpeople);
    
//进行Joseph操作
    JosephCircle(mylist,firstkey);
    return 0;
}