#include "main.h"
#include <stdio.h>
#include <stdlib.h>

void initial(PSeqQuence P)
{
    P->front = 0;
    P->rear = 0;
}

int queueLength(PSeqQuence P)
{
    return (P->rear - P->front + 5) % 5;
}

int checkFilled(PSeqQuence P)
{
    if((P->rear + 1)%5 == P->front) return 1;
    else return 0;
}

void enQueue(PSeqQuence P)
{
    int value;
    if(checkFilled(P)){
        printf("The queue is filled !\n");
        exit(0);
    }

    printf("Input the enqueue value\n");
    scanf("%d",&value);

    P->data[P->rear] = value;
    P->rear = (P->rear + 1)%MAXSIZE;
}

int deQueue(PSeqQuence P)
{
    int value;
    if(P->rear == P->front){
        printf("The Empty queue\n");
        exit(0);
    }

    value = P->data[P->front];
    P->front = (P->front + 1)%MAXSIZE;

    printf("The value is %d\n",value);
    return value;
}

void main()
{
    SeqQuence P;
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