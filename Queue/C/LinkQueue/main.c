#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void initial(PQueue P)
{
    PNode headNode = (PNode)malloc(sizeof(NODE));
    if(headNode == NULL){
        printf("malloc job failed ! \n");
        exit(-1);
    }

    P->front = headNode;
    P->front->next = NULL;
    P->rear = P->front;
}

void enQueue(PQueue P)
{
    elemType value;
    if(P == NULL){
        printf("Invaliad queue !\n");
        exit(-1);
    }

    PNode newNode = (PNode)malloc(sizeof(NODE));
    if(newNode == NULL){
        printf("malloc job failed ! \n");
        exit(-1);
    }

    printf("Input the value \n");
    scanf("%d",&value);

    newNode->data = value;
    newNode->next = NULL;
    P->rear->next = newNode;
    P->rear = newNode;
}

int deQueue(PQueue P)
{
    int value;
    if(P->rear == P->front){
        printf("Empty queue !\n");
        exit(-1);
    }

    PNode deNode =P->front->next;
    value = deNode->data;
    P->front->next = deNode->next;

    if(deNode->next == NULL){
        P->rear = P->front;
    }

    printf("The value is %d\n",value);

    return value;
}

void main()
{
    QUEUE P;
    initial(&P);
    enQueue(&P);
    enQueue(&P);
    enQueue(&P);
    enQueue(&P);
    deQueue(&P);
    deQueue(&P);
    deQueue(&P);
    deQueue(&P);
    deQueue(&P);
}
