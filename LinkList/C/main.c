#include "main.h"
#include "stdio.h"
#include "stdlib.h"

PNODE initial(PNODE PHead,PNODE PTail)
{
    int length,i,value;
    //指向首节点的指针，也就是头指针
    PHead = (PNODE)malloc(sizeof(struct NODE));
    if(PHead == NULL){
        printf("malloc for head pointer failed. Exit !\n");
        exit(1);
    }
    else{
        //PHead是头指针，指向的是头结点。PHead->next是头结点的
        //下一个节点也就是首节点(第一个拥有数据域的节点)。此时首节点
        //是NULL;
        PHead->next = NULL;
        //此时头尾指针相同
        PTail = PHead;

        //链表的初始长度
        printf("Input the initial length of the link list \n");
        scanf("%d",&length);

        for(i = 0; i < length; i++){
            //newNode是指向新节点的指针。 newNode->data是新节点
            //的数据域。newNode->next是指向新节点的下一个节点的指针
            PNODE newNode = (PNODE)malloc(sizeof(struct NODE));

            printf("Input the value of the new node \n");
            scanf("%d",&value);

            newNode->data = value;
            PTail->next = newNode;
            newNode->next = NULL;
            PTail = newNode;
        }
    }

    return PHead;
}

void insert(PNODE PHead)
{
    PNODE p = PHead;
    int postion,value,i = 0;

    printf("Input the position and value\n");
    scanf("%d%d",&postion,&value);


    //寻找插入位置的前驱节点。这里需要注意当循环结束的时候 i = postion-1
    while(p != NULL && i < postion-1){
        p = p->next;
        i++;
    }

    if(p == NULL || i > postion - 1){
        printf("Position invailad ! Exit !\n");
        exit(1);
    }

    PNODE newNode = (PNODE)malloc(sizeof(struct NODE));
    newNode->data = value;
    newNode->next = p->next;
    p->next = newNode;
}

void traversal(PNODE PHead)
{
    int i = 1;
    PNODE p;
    if(PHead == NULL){
        printf("Invailad link list . Exit !\n");
        exit(1);
    }
    if( (p = PHead->next) == NULL){
        printf("Empty link list . Exit !\n");
        exit(0);
    }

    printf("Traversal begin.\n");
    while (p != NULL){
        printf("The %d value is %d\n",i,p->data);
        p = p->next;
        i++;
    }
    printf("Traversal end.\n");
}

void delete(PNODE PHead)
{
    PNODE p = PHead;
    int i,postion;

    printf("Input the delete position\n");
    scanf("%d",&postion);

    for(i = 1; i < postion; i++){
        if(p == NULL){
            if(i == 0) printf("Invaliad list. \n");
            else if(i == 1) printf("Empty List.\n");
            else printf("Position invailaid. Do nothing. Exit !\n");
            exit(1);
        }
        p = p->next;
    }
    //循环完以后P指向要删除节点的前驱
    if(p == NULL){
        printf("Position invailaid. Do nothing. Exit !\n");
        exit(1);
    }
    //element就是要删除的节点
    PNODE element = p->next;
    //如果要删除的节点不存在
    if(element == NULL) {
        printf("Position invailaid. Do nothing. Exit !\n");
        exit(1);
    }
     //算法中不需要判断被删除位置的下一个位置是否为null
    else p->next = element->next;
}

void clear(PNODE PHead)
{
    if(PHead == NULL){
        printf("invaliad link list ! \n");
        exit(1);
    }
    if(PHead->next = NULL){
        printf("Empty link list ! \n");
        exit(0);
    }

    PNODE p = PHead;
    PNODE q;
    while(p != NULL){
        q = p->next;
        free(p);
        p = q;
    }
}

void main()
{
    PNODE PHead,PTail;
    PHead = initial(PHead,PTail);
    traversal(PHead);
    //insert(PHead);
    //delete(PHead);
    clear(PHead);
    traversal(PHead);
}

