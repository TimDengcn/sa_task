#include "main.h"

void createCirList(CirList L,int n){
    CirNode *nownode=(CirNode *)malloc(sizeof(CirNode));
    nownode=L;
    for(int i=0;i<n;i++){
        nownode=nownode->next;
    }
    nownode->next=L->next;
}