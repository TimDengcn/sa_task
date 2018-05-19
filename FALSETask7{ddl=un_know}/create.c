#include "main.h"

//构造链表环，其中链表头仍然存在，指向链表环中的一员
void createCirList(CirList L,int n){
    CirNode *nownode=(CirNode *)malloc(sizeof(CirNode));
    nownode=L;
    for(int i=0;i<n;i++){
        nownode=nownode->next;
    }
    nownode->next=L->next;
}