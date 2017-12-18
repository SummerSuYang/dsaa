#include "../../SeqList/C/main.h"

#ifndef DSAA_MAIN_H
#define DSAA_MAIN_H
#endif

//链表节点的数据类型
typedef struct NODE
{
    int data;
    struct Node *next;
};

//链表头（尾）指针的数据类型
typedef struct NODE *PNODE;
