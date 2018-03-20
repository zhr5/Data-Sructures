#pragma once
//#pragma once是一个比较常用的C/C++杂注，
//只要在头文件的最开始加入这条杂注，
//就能够保证头文件只被编译一次。


/*
求解关键路径问题，
必须是有向无环图才有关键路径

*/
#include<iostream>
#include<stack>
#include<string>
using namespace std;
//表结点
struct ArcNode {
	int start;    //弧尾的顶点的下标
	int end;    //弧头的顶点的下标 ，有箭头的一方
	int weight; //弧的权重
	ArcNode * next; //下一条弧
};
//头结点
struct Vnode {
	ArcNode * firstarc;  //第一条依附在该该顶点的弧
	string data;
};

class Graph_DG {
private:
	int vexnum; //顶点个数
	int edge;   //边的条数
	Vnode * arc; //邻接表
	int *indegree; //各个顶点的入度情况
	stack<int> List; //拓扑序列中各个边的情况
	int * ve;  //记录每个顶点的最早发生时间
	int * vl;  //记录每个顶点最迟发生时间

public:
	Graph_DG(int vexnum, int edge);
	~Graph_DG();//析构函数
	bool check_edge_value(int, int, int); //检查边的信息是否合法
	void createGraph();//创建一个新的图
	void print();//打印图的邻接表
	bool topological_sort();
	bool CriticalPath();
};
