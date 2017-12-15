#include <stdio.h>
#include <malloc.h>

typedef struct queue{
    int element;
    struct queue *next;
}queue;

int getfront(queue * queuehead);
int dequeue(queue * queuehead);
void enqueue(int element,queue * queuehead);
int isempty(queue * queuehead);
queue * queuecreate();

int main(){
    queue * myqueue=queuecreate();

    enqueue(12,myqueue);
    enqueue(34,myqueue);
    enqueue(56,myqueue);

    printf("%d\n",getfront(myqueue));
    printf("%d\n",dequeue(myqueue));
    if(!isempty(myqueue)){
        printf("%d\n",dequeue(myqueue));
    }
    if(!isempty(myqueue)){
        printf("%d\n",dequeue(myqueue));
    }
    if(!isempty(myqueue)){
        printf("%d\n",dequeue(myqueue));
    }
    if(!isempty(myqueue)){
        printf("%d\n",dequeue(myqueue));
    }
    return 0;
}

int getfront(queue * queuehead){
    int element;

    element=queuehead->next->element;

    return element;
}

int isempty(queue * queuehead){
    if(queuehead->next==NULL){
        return 1;
    }else{
        return 0;
    }
}

int dequeue(queue * queuehead){
    int element;
    queue *queuetemp = queuehead->next->next;

    element=queuehead->next->element;
    free(queuehead->next);
    queuehead->next=queuetemp;

    return element;
}
void enqueue(int element,queue * queuehead){
    queue* queuetemp=queuehead;
    queue* queue1=(queue*)malloc(sizeof(queue));

    queue1->next=NULL;
    queue1->element=element;

    while(queuetemp->next!=NULL){
        queuetemp=queuetemp->next;
    }

    queuetemp->next=queue1;

}

queue * queuecreate(){
    queue * queue1=(queue *)malloc(sizeof(queue));
    queue1->next=NULL;
    return queue1;
}