#ifndef DSAA_MAIN_H
#define DSAA_MAIN_H
#endif //DSAA_MAIN_H

/**
 * 节点
 */
typedef struct NODE
{
    int data;
    struct NODE *next;
};

/**
 * 指向节点的指针
 */
typedef struct NODE *PNode;

/**
 * 栈
 */
typedef struct STACK
{
    PNode bottom;
    PNode top;
};

/**
 * 指向栈的指针
 */
typedef struct STACK *PStack;
