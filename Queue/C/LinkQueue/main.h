#ifndef DSAA_MAIN_H
#define DSAA_MAIN_H
#endif //DSAA_MAIN_H

typedef int elemType;
typedef struct NODE
{
    elemType data;
    struct NODE *next;
}NODE,*PNode;

typedef struct QUEUE
{
    PNode front;
    PNode rear;
}QUEUE,*PQueue;