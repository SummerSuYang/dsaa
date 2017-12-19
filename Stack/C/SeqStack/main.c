#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

void initial(PStack P){
    if(P == NULL){
        printf("Invaild stack ! \n");
        exit(-1);
    }
    P->maxSize = 5;
    P->length = 0;
}

void push(PStack P)
{
    int value;
    if(P == NULL){
        printf("Invaliad stack ! \n");
        exit(-1);
    }
    if(P->length == P->maxSize){
        printf("The stack has filled ! \n");
        exit(0);
    }
    printf("Input the value that push to the stack. \n");
    scanf("%d",&value);
    P->data[P->length] = value;
    P->length++;
}

int pop(PStack P)
{
    if(P == NULL){
        printf("Invaliad stack ! \n");
        exit(-1);
    }
    if(P->length == 0){
        printf("Empty stack ! \n");
        exit(0);
    }

    P->length--;
    int value = P->data[P->length];
    printf("The pop value is %d\n",value);
    return P->data[P->length];
}

void traversal(PStack P)
{
    int i;
    if(P == NULL){
        printf("Invaliad stack ! \n");
        exit(-1);
    }
    if(P->length == 0){
        printf("Empty stack ! \n");
        exit(-1);
    }

    for(i = P->length-1; i >= 0; i--){
        printf("%d\n",P->data[i]);
    }
}

void main()
{
    STACK stack;
    initial(&stack);
    push(&stack);
    push(&stack);
    push(&stack);
    push(&stack);
    push(&stack);
    pop(&stack);
    traversal(&stack);
}
