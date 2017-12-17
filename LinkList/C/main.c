//
// Created by suyang on 2017/12/17.
//

#include "main.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void initial(struct Node *L)
{

}

elemType randNumber()
{
    srand(time(0));
    return rand()%100+1;
}