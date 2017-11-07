#include <stdio.h>
#include <malloc.h>
#include <mem.h>

typedef struct NODE
{
    int num;
    struct NODE *next;
}node;
/*将输入的数加为列表的下一个元素，并且返回当最后一个元素的指针*/
node* keyin(node *now,node *root,int tem){
    node *p1;
    p1=(node *)malloc(sizeof(node));
    now->next=p1;
    p1->num=tem;
    p1->next=NULL;
    return p1;
}
/*输出当前列表的所有元素*/
void putout(node *root){
    node *now=root;
    while(now!=NULL){
        printf("%d \n",now->num);
        now=now->next;
    }
}
/*记录当前指针，当前指针的前一个指针和后一个指针，将当前指针的next指向前一指针后，将当前指针的地址直接赋给前一个指针并将后一指针的地址直接赋给当前指针，然后将后一指针赋值为当前后一指针的next，
 *即将这三个指针整体后移一格，其中后一指针用于锚定，前一指针与当前指针为操作实体*/
node * ReverseList(node *old_root){
    node *now=(node *)malloc(sizeof(node));
    node *now_next=(node *)malloc(sizeof(node));
    node *now_last=(node *)malloc(sizeof(node));s
    now_last=old_root;
    now=old_root->next;
    while(now->next!=NULL){
        now_next=now->next;
        now->next=now_last;
        now_last=now;
        now=now_next;
    }
    now->next=now_last;
    old_root->next=0;
    return now;
}

int main(){
    node *root;
    node *now;
    int tem_num;
    root=(node *)malloc(sizeof(node));
    now=root;
    printf("key in a series of nums and key in 0 to go ahead :\n");
    scanf("%d",&tem_num);
    root->num=tem_num;

    while(1){
        scanf("%d",&tem_num);
        if(tem_num==0)
            break;
        else{
            now=keyin(now,root,tem_num);
        }
    }
    printf("****************************\nThe origin list :\n");
    putout(root);
    root=ReverseList(root);
    printf("****************************\nThe Reversed list :\n");
    putout(root);
    return 0;
}

