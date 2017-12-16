#ifndef DSAA_SEQLIST_H
#define DSAA_SEQLIST_H
#endif
#define MAXSIZE 4;
#define INCREMENT 10;
typedef int elemType;
typedef struct seqList
{
    //存储数据的单元
    elemType *elem;
    //表当前的长度
    int length;
    //表最大的长度
    int listSize;
    //当表的长度超过最大长度时，表会自动“增长”，increment即为
    //每次自动增长的幅度
    int increment;
};
