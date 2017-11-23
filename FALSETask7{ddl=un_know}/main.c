#include "main.h"

int main(){
    int numberofpeople;
    int firstkey;
    CirList mylist;
    CirNode *nownode;
    printf("key the number of people :");
    scanf("%d",&numberofpeople);

    mylist=(CirList)malloc(sizeof(CirNode));
    mylist->number=0;
    mylist->data=0;
    mylist->next=NULL;
    nownode=mylist;
    for(int n=0;n<numberofpeople;n++){
        CirNode *tempnode=(CirNode *)malloc(sizeof(CirNode));
        tempnode->number=n+1;
        scanf("%d",&tempnode->data);
        tempnode->next=NULL;
        nownode->next=tempnode;
        nownode=tempnode;
    }

    printf("\nkey the key of the first people :");
    scanf("%d",&firstkey);
    putchar('\n');

    createCirList(mylist,numberofpeople);
    JosephCircle(mylist,firstkey);
    return 0;
}