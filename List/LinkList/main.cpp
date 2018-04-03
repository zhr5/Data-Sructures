
/**********************************
*                                *
* 文件名: main.cpp                *
*                                *
* 内  容: 线性链表的主函数入口        *
*                                *
**********************************/

#include"Status.h"
#include"LinkList.h"
#include<stdio.h>
#include<stdlib.h>

int main() {
	struct LNode *La;
	
	InitList_L(La);

	ListInsert_L(La, 1, 1);
	
	ListInsert_L(La, 2, 2);

	ListInsert_L(La, 3, 5);

	ListInsert_L(La, 4, 7);

	ListInsert_L(La, 5, 10);

	ListTraverse_L(La, visit_display_L);

	printf("\n");



	struct LNode *Lb;

	InitList_L(Lb);

	ListInsert_L(Lb, 1, 0);

	ListInsert_L(Lb, 2, 3);

	ListInsert_L(Lb, 3, 6);

	ListInsert_L(Lb, 4, 7);

	ListInsert_L(Lb, 5, 10);

	ListTraverse_L(Lb, visit_display_L);

	printf("\n");



	struct LNode *Lc;

	MergeList_L(La, Lb, Lc);

	ListTraverse_L(Lc, visit_display_L);

	printf("\n");

	ListInverse_L(Lc);

	ListTraverse_L(Lc, visit_display_L);


	return 0;
	
}