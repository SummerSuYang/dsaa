#include "bfs.h"
#include <stdio.h>
#include <malloc.h>
//邻接表
AdjList adjList;
int initialQueue(PQueue p)
{
    p->front = p->rear = 0;
}

int enQueue(PQueue p, int value)
{
    p->data[p->rear] = value;
    p->rear++;
}

int deQueue(PQueue p)
{
    int tmp = p->front;
    p->front++;
    return p->data[tmp];
}

int checkEmpty(PQueue p)
{
    if(p->front == p->rear) return 1;
    else return 0;
}

/**
 * 初始化邻接表
 * @return
 */
int initialAdjList()
{
    int vertexNum,edgeNum,i,j;
    PEdgeNode e;

    printf("Input the num of vertex and edges\n");
    scanf("%d%d",&vertexNum,&edgeNum);

    //顶点数目和边的长度
    adjList.vertexNums = vertexNum;
    adjList.edgeNums = edgeNum;

    for(i = 0; i < vertexNum; i++){
        int m;
        printf("Input the value of vertex\n");
        scanf("%d",&m);
        adjList.list[i].data = m;
        adjList.list[i].firstEdge = NULL;
    }

    for(i = 0; i < edgeNum; i++){
        int m, n;
        printf("Input the edge\n");
        scanf("%d%d",&m, &n);

        e = (PEdgeNode)malloc(sizeof(EdgeNode));
        //相对于顶点n它的邻接顶点是m
        e->adjvex = m;
        //头插法
        e->next = adjList.list[n].firstEdge;
        adjList.list[n].firstEdge = e;

        e = (PEdgeNode)malloc(sizeof(EdgeNode));
        //相对于顶点m它的邻接顶点为n
        e->adjvex = n;
        //头插法
        e->next = adjList.list[m].firstEdge;
        adjList.list[m].firstEdge = e;
    }

    return vertexNum;
}

/**
 * 初始化“访问”数组
 * @param visits
 * @return
 */
int initialVisits(int *visits,int nums)
{
    int i;
    for(i = 0; i < nums; i++){
        visits[i] = 0;
    }

    return 0;
}

/**
 * 邻接表的广度搜索
 * @param p
 * @param visits
 * @return
 */
int BFS(PQueue p, int *visits)
{
    int i;
    for(i = 0; i < adjList.vertexNums; i++){
        if(visits[i] == 0){
            printf("%d\n", adjList.list[i].data);
            visits[i] = 1;
            enQueue(p,adjList.list[i].data);
            while (! checkEmpty(p)){
                int j = deQueue(p);
                PEdgeNode firstEdge = adjList.list[j].firstEdge;
                while (firstEdge){
                    enQueue(p, firstEdge->adjvex);
                    firstEdge = firstEdge->next;
                }
                deQueue(p);
            }
        }
    }
}

int main()
{
    int visits[MAX],vertexNums;
    Queue q;

    vertexNums = initialAdjList();
    initialVisits(visits,vertexNums);
    initialQueue(&q);
    BFS(&q, visits);
}
