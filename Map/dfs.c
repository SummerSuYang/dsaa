#include "dfs.h"
#include <stdio.h>
#include <stdlib.h>

//邻接矩阵
AdjMatrix adjMatrix;
//邻接表
AdjList adjList;

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
 * 初始化“邻接矩阵图”
 * @return
 */
int initialAdjMatrix()
{

    int vertexNum,edgeNum,i,j;

    printf("Input the num of vertex and edges\n");
    scanf("%d%d",&vertexNum,&edgeNum);

    //顶点数目和边的长度
    adjMatrix.vertexNums = vertexNum;
    adjMatrix.edgeNums = edgeNum;

    //初始化矩阵
    for(i = 0; i < adjMatrix.vertexNums; i++){
        for(j = 0; j < adjMatrix.vertexNums; j++)
        adjMatrix.matrix[i][j] = FALSE;
    }

    //初始化顶点
    printf("Input the vertex\n");
    for(i = 0; i < vertexNum; i++){
        int value;
        scanf("%d",&value);
        adjMatrix.vertex[i] = value;
    }

    //初始化边
    printf("Input the edges i,j\n");
    for(i = 0; i < edgeNum; i++){
        int m,n;
        scanf("%d%d",&m,&n);
        adjMatrix.matrix[m][n] = adjMatrix.matrix[n][m] = 1;
    }

    //返回顶点的数目
    return vertexNum;
}

/**
 * 邻接矩阵递归的核心算法
 * @param i
 * @param visits
 * @return
 */
int DFS(int i, int *visits)
{
    int j;
    //记录已经遍历
    visits[i] = 1;
    printf("%d\n",adjMatrix.vertex[i]);
    //沿着已经遍历过的顶点的“边”继续遍历
    for(j = 0; j < adjMatrix.vertexNums; j++){
        if(adjMatrix.matrix[i][j] == 1 && visits[j] == 0)
            DFS(j,visits);
    }
}

/**
 * 邻接表递归的核心算法
 * @param i
 * @param visits
 * @return
 */
int DFSList(int i, int *visits)
{
    //记录已经遍历
    visits[i] = 1;
    printf("%d\n",adjList.list[i].data);
    PEdgeNode firstEdge = adjList.list[i].firstEdge;
    while(firstEdge){
        if(visits[firstEdge->adjvex] == 0)
            DFSList(firstEdge->adjvex, visits);
        firstEdge = firstEdge->next;
    }
}

/**
 * 邻接矩阵递归
 * @param visits
 * @return
 */
int DFSTravesel(int *visits)
{
    int i;
    for(i = 0; i < adjMatrix.vertexNums; i++){
        //如果还没有遍历就遍历
        if(visits[i] == 0)
            DFS(i,visits);
    }
}

/**
 * 邻接表递归
 * @param visits
 * @return
 */
int DFSTraveselList(int *visits)
{
    int i;
    for (i = 0; i < adjList.vertexNums; i++){
        if(visits[i] == 0)
            DFSList(i,visits);
    }
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

int main()
{
    int visits[MAX],vertexNums;

    //vertexNums = initialAdjMatrix();
    vertexNums = initialAdjList();

    initialVisits(visits,vertexNums);

    DFSTraveselList(visits);
}



