#include "main.h"

void JosephCircle(CirList L,int m){
    CirNode *nownode=(CirNode *)malloc(sizeof(CirNode));
    CirNode *lastnode=(CirNode *)malloc(sizeof(CirNode));
    CirNode *firstnode;

    firstnode=L->next;
    nownode=firstnode->next;

    if(nownode->next==nownode){
        printf("1");
        return;
    }

    while(nownode!=firstnode){
        lastnode=nownode;
        nownode=lastnode->next;
    }

    while(nownode->next!=nownode){
        for(int n=0;n<m-1;n++){
            lastnode=nownode;
            nownode=lastnode->next;
        }
        printf("%d\t",nownode->number);
        m=nownode->data;
        lastnode->next=nownode->next;
        free(nownode);
        nownode=lastnode->next;
    }
    printf("%d\nover.\n",nownode->number);
}