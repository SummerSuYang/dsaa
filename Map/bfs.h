#ifndef DSAA_BFS_H
#define DSAA_BFS_H
#endif
#define MAX 100
typedef struct
{
    int data[MAX];
    int front;
    int rear;
}Queue, *PQueue;

//邻接矩阵
typedef struct
{
    int vertex[MAX];
    int matrix[MAX][MAX];
    int vertexNums, edgeNums;
}AdjMatrix;

//邻接表中的“边”节点
typedef struct
{
    int adjvex;
    struct EdgeNode *next;
}EdgeNode, *PEdgeNode;

//顶点
typedef struct
{
    int data;
    PEdgeNode firstEdge;
}VertexNode,ChainList[MAX];

//多个节点多个链表
typedef struct
{
    ChainList list;
    int edgeNums,vertexNums;
}AdjList;
