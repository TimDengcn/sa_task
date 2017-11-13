#include <stdio.h>
#include <malloc.h>

typedef struct stack{
    int element;
    struct stack *next;
}stack;

int gettop(stack * stackhead);
int pop(stack * stackhead);
void push(int element,stack * stackhead);
stack * stackcreate();

int main(){
    stack * mystack=stackcreate();

    push(12,mystack);
    push(34,mystack);
    push(56,mystack);

    printf("%d\n",gettop(mystack));
    printf("%d\n",pop(mystack));
    printf("%d\n",pop(mystack));
    printf("%d\n",pop(mystack));

    return 0;
}

int gettop(stack * stackhead){
    int element;

    element=stackhead->next->element;

    return element;
}


int pop(stack * stackhead){
    int element;
    stack *stacktemp = stackhead->next->next;

    element=stackhead->next->element;
    free(stackhead->next);
    stackhead->next=stacktemp;

    return element;
}
void push(int element,stack * stackhead){
    stack* stack1=(stack*)malloc(sizeof(stack));

    stack1->next=stackhead->next;
    stack1->element=element;

    stackhead->next=stack1;
}

stack * stackcreate(){
    stack * stack1=(stack *)malloc(sizeof(stack));
    stack1->next=NULL;
    return stack1;
}