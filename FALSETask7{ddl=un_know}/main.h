#ifndef CCLASS_MAIN_H
#define CCLASS_MAIN_H
#include <malloc.h>
#include <stdio.h>

typedef struct CirNode{
    int data;
    int number;
    struct CirNode * next;
}CirNode,*CirList;

extern void createCirList(CirList,int);
extern void JosephCircle(CirList L,int m);

#endif