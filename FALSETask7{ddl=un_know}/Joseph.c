#include "main.h"

//进行Joseph操作
void JosephCircle(CirList L,int m){

//初始化操作元
    CirNode *nownode=(CirNode *)malloc(sizeof(CirNode));
    CirNode *lastnode=(CirNode *)malloc(sizeof(CirNode));
    CirNode *firstnode;

    firstnode=L->next;
    nownode=firstnode->next;

//如果链表只有一个元，pass
    if(nownode->next==nownode){
        printf("1");
        return;
    }

//寻找链表指向元的前一个元，应对出现输入的key为1
    while(nownode!=firstnode){
        lastnode=nownode;
        nownode=lastnode->next;
    }

//当当前元的下位元不是自身（即当前的元的next不指向自己时），移动m-1格
    while(nownode->next!=nownode){
        for(int n=0;n<m-1;n++){
            lastnode=nownode;
            nownode=lastnode->next;
        }

//打印当前元的number，以及更新m的值，然后删除当前元
        printf("%d\t",nownode->number);
        m=nownode->data;
        lastnode->next=nownode->next;
        free(nownode);
        nownode=lastnode->next;
    }
    
//打印出最后所剩的一个元的number
    printf("%d\nover.\n",nownode->number);
}