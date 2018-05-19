#ifndef CCLASS_MAIN_H
#define CCLASS_MAIN_H
#include <malloc.h>
#include <stdio.h>

//初始化结构体
typedef struct CirNode{
    int data;
    int number;
    struct CirNode * next;
}CirNode,*CirList;

//函数声明
extern void createCirList(CirList,int);
extern void JosephCircle(CirList L,int m);

#endif