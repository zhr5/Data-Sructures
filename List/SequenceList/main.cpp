
/**********************************
*                                *
* 文件名: main.h                  *
*                                *
* 内  容: 线性表的主函数入口         *
*                                *
**********************************/

#include<stdio.h>
#include<stdlib.h>
#include"Status.h"
#include"SequenceList.h"


int main() {
	SqList L1, L2;
	InitList(L1);
	ListInsert(L1, 1, 3);
	ListInsert(L1, 2, 5);
	ListInsert(L1, 3, 8);
	ListInsert(L1, 4, 11);
	ListTraverse(L1);
	printf("\n");

	InitList(L2);
	ListInsert(L2, 1, 2);
	ListInsert(L2, 2, 6);
	ListInsert(L2, 3, 8);
	ListInsert(L2, 4, 9);
	ListInsert(L2, 5, 11);
	ListInsert(L2, 6, 15);
	ListInsert(L2, 7, 20);
	ListTraverse(L2);
	printf("\n");

	//Union(L1, L2);
	//ListTraverse(L1);
	SqList Lc;
	MergeList(L1, L2, Lc);
	ListTraverse(Lc);


	return 0;

}
