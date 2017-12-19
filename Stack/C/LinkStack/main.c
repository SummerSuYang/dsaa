#include "main.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

/**
 * 初始化
 * @param P
 */
void initial(PStack P)
{
    //申请一个节点
    P->top = (PNode)malloc(sizeof(struct NODE));
    if(P->top == NULL){
        printf("Malloc job failed\n");
        exit(-1);
    }

    //尾节点等于首节点
    P->bottom = P->top;
    P->top->next = NULL;
}

/**
 * 压栈
 * @param P
 */
void push(PStack P)
{
    int value;
    PNode newNode = (PNode)malloc(sizeof(struct NODE));
    if(newNode == NULL){
        printf("Malloc job failed\n");
        exit(-1);
    }

    printf("Input the value\n");
    scanf("%d",&value);
    newNode->data = value;
    newNode->next = P->top;
    P->top = newNode;
}

/**
 * 判断栈是否为空
 * @param P
 * @return
 */
int checkEmpty(PStack P)
{
    if(P->top == P->bottom) return 1;
    else return 0;
}

/**
 * 弹栈
 * @param P
 */
void pop(PStack P)
{
    if(checkEmpty(P)){
        printf("Empty Stack\n");
        exit(-1);
    }
    //要弹出的节点
    PNode tmp = P->top;
    //节点的值
    int value = tmp->data;
    //将当前top节点的下一个节点给top节点
    P->top = P->top->next;
    free(tmp);
    printf("Pop value is %d\n",value);
};

/**
 * 从栈顶开始遍历
 * @param P
 */
void traversal(PStack P)
{
    int i = 1;
    if(checkEmpty(P)){
        printf("Empty Stack\n");
        exit(-1);
    }
    PNode tmp= P->top;
    while(tmp != P->bottom){
        printf("The %d value is %d\n",i,tmp->data);
        tmp = tmp->next;
        i++;
    }
}

void clear(PStack P)
{
    if(P == NULL){
        printf("Invaliad Stack ! \n");
        exit(-1);
    }
    if(checkEmpty(P)){
        printf("Empty Stack !\n");
        exit(0);
    }

    PNode p = P->top;
    while (p != P->bottom){
        PNode q = p;
        free(p);
        p = q->next;
    }
    P->top = P->bottom;
}

void main()
{
    struct STACK P;
    initial(&P);
    push(&P);
    push(&P);
    push(&P);
    push(&P);
    //pop(&P);
    traversal(&P);
    clear(&P);
    traversal(&P);
}

