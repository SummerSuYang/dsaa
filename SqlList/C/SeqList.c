#include <stdio.h>
#include <malloc.h>
#include "SeqList.h"

#define OK 1;
#define ERROR 0;

int listSize = MAXSIZE
int increment = INCREMENT

typedef int status;

/**
 * 顺序表初始化
 * @param L
 * @param size
 * @return
 */
status initialList(struct seqList *L,int listSize,int increment)
{
    //向内存申请存储单元,malloc函数返回内存地址
    //listSize * sizeof(elemType)决定了内存的大小
    // (elemType *)决定了存储在内存中变量的类型
    L->elem = (elemType *)malloc(listSize * sizeof(elemType));
    if(L->elem == NULL){
        printf("Dynamic application of memory space failed !");
        return ERROR;
    }

    //初始长度为0
    L->length = 0;
    //最大长度
    L->listSize = listSize;
    //扩容的增幅
    L->increment = increment;

    return OK;
}

/**
 * 创建顺序表
 * @param L
 * @param l
 * @return
 */
status createList(struct seqList *L)
{
    int i;

    //表的长度
    printf("Please input the length of the sequence list\n");
    scanf("%d",&L->length);

    //如果输入的长度大于线性表的最大长度就要扩容
    if(L->length > L->listSize){
        L->elem = (elemType *)realloc(L->elem, (L->listSize + L->increment) * sizeof(elemType));
    }

    if(! L->elem) return ERROR;

    //输入元素
    printf("Please input the elements.The length is %d\n",L->length);
    for(i = 0; i < L->length; i++){
        scanf("%d",&L->elem[i]);
    }

    return OK;
}

/**
 * 遍历整个顺序表
 * @param L
 * @return
 */
status traversal(struct seqList *L)
{
    int i;

    if(L->elem == NULL){
        printf("The sequence List do not exists !\n");
        return ERROR;
    }
    if(L->length == 0){
        printf("Empty list\n");
        return OK;
    }

    for(i = 0; i < L->length; i++) {
        printf("%4d\n",L->elem[i]);
    }

    return OK;
}

/**
 * 查找某一个元素的位置
 * @param L
 * @return
 */
status getPosition(struct seqList *L)
{
    int i,j=0;
    int position[L->length] ;
    elemType e;

    printf("Input the value you find\n");
    scanf("%d",&e);

    if(L->elem == NULL){
        printf("The sequence List do not exists !\n");
        return ERROR;
    }
    if(L->length == 0){
        printf("Empty list\n");
        return OK;
    }

    for(i = 0; i < L->length; i++){
        if(L->elem[i] == e){
            position[j] = i;
            j++;
        }
    }

    if(j == 0){
        printf("The element %d is not in the list !%d\n",e);
        return OK;
    }
    else{
        printf("The following are the element position\n");
        for(i = 0; i < j; i++){
            printf("%d,",position[i]+1);
        }
        printf("\n");

        return OK;
    }
}

status getElement(struct seqList *L)
{
    int position;
    if(L->elem == NULL){
        printf("The sequence List do not exists !");
    }
    if(L->length == 0){
        printf("Empty list\n");
    }

    printf("Input the position\n");
    scanf("%d",&position);

    if(position <= 0 || position > L->length ){
        printf("The input position %d is unexpected.The list length is %d\n",position,L->length);

        return ERROR;
    }

    printf("The element is %d",L->elem[position-1]);

    return OK;
}

status set(struct seqList *L)
{
    int position,value;
    if(L->elem == NULL){
        printf("The sequence List do not exists !\n");
        return ERROR;
    }

    printf("Input both the position and value \n");
    scanf("%d %d",&position,&value);
    if(position <= 0 || position > L->length){
        printf("The inputting position is unexpected\n");
        return ERROR;
    }
    L->elem[position -1] = value;

    return OK;
}

status insert(struct seqList *L)
{
    int position,i;
    elemType value;
    if(L->elem == NULL){
        printf("The sequence List do not exists !\n");
        return ERROR;
    }

    printf("Input the position and value \n");
    scanf("%d %d",&position,&value);

    if(position <= 0 || position > L->listSize){
        printf("The inputting position is unexpected. The max size of the list is %d",L->listSize);

        return ERROR;
    }

    if(position == L->length + 1){
        L->elem[position - 1] = value;

        return OK;
    }

    for(i = L->length; i >= position-1; i--) {
        L->elem[i + 1] = L->elem[i];
    }

    L->elem[position - 1] = value;
    L->length++;

    return OK;
}

status deleteByPosition(struct seqList *L)
{
    int position,i;

    if(L->elem == NULL){
        printf("The sequence List do not exists !\n");
        return ERROR;
    }
    if(L->length == 0){
        printf("Empty list\n");
        return OK;
    }

    printf("Input the position\n");
    scanf("%d",&position);

    if(position == L->length){
        L->length--;

        return OK;
    }

    for(i = position; i < L->length; i++){
        L->elem[i - 1] = L->elem[i];
    }
    L->length--;

    return OK;
}
/**
 * 清空顺序表
 * @param L
 */
void clear(struct seqList *L)
{
    if(L->elem == NULL){
        printf("The sequence List do not exists !");
    }
    if(L->length == 0){
        printf("Empty list\n");
    }

    L->length = 0;
}

/**
 * 销毁顺序表
 * @param L
 * @return
 */
status destroy(struct seqList *L)
{
    if(L->elem == NULL){
        printf("The sequence List do not exists !\n");
        return ERROR;
    }
    //free函数只是告诉操作系统“我要把申请的资源释放掉”，这时资源并没有
    //完全的从内存中释放掉，还需要我们把指向资源的指针设置为null
    free(L->elem);
    L->elem = NULL;
    printf("Free the space successfully ! \n");

    return OK;
}





int main()
{
    struct seqList L;
    initialList(&L,listSize,increment);
    createList(&L);
    //find(&L);
    //destroy(&L);
    traversal(&L);
    //getPosition(&L);
    //getElement(&L);
    //set(&L);
    //insert(&L);
    deleteByPosition(&L);
    traversal(&L);
}