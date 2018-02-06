/**********************************
*                                 *
* 文件名: LinkList.cpp             *
*                                 *
* 内  容: 线性链表的基本操作函数实现    *
*                                 *
**********************************/

#include"Status.h"
#include"LinkList.h"
#include<stdio.h>
#include<stdlib.h>

void InitList_L(struct LNode * &L) {

	L=(struct LNode*)malloc(LEN);
	if (L)	exit(OVERFLOW);
	L->next = NULL;

}

Status  DestoryList_L(struct LNode * &L) {

	struct LNode *p;
	if (!L) return OK;
	while (L)
	{
		p = L->next;
		free(L);
		L = p;
	}
	p = NULL;
	printf("完成链式表的销毁\n");
	return OK;

}

void ClearList_L(struct LNode * &L) {
	//将表L重置为空表

	L->next = NULL;
}

bool ListEmpty_L(struct LNode * &L) {
	//判断是否为空表，是返回true, 否则返回false

	if (NULL == L->next)

		return true;

	else

		return false;
}

int ListLength_L(struct LNode * &L) {
	int len = 0;
	struct LNode *p = L->next;  // p指向第一个结点

	while (NULL != p) {

		len++;

		p = p->next;

	}

	return len;
}

Status GetElem_L(struct LNode * &L, int i, ElemType &e) {

	struct LNode *p = L->next;  // p指向第一个结点
	int j = 1;

	while ( p && j < i) {//顺指针往下找,直到p指向
		p = p->next;
		++j;
	}

	if (!p || j > i) {
		return ERROR;//第i个元素不存在
	}

	e = p->data;
	return OK;
}

int LocateElem_L(struct LNode * &L, ElemType e) {

	struct LNode *p = L->next;  // p指向第一个结点
	int i = 0;
	if (NULL != p) {
		i++;
		if (e == p->data)
			return i;
		p = p->next;
	}
	return 0;

}

Status PriorElem_L(struct LNode * &L, ElemType cur_e, ElemType &pre_e) {
	//要求线性表L存在

	//若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败，pre_e无定义
	int i = 0;
	struct LNode *p = L->next;  // p指向第一个结点
	if (NULL != p) {
		i = LocateElem_L(L, cur_e);
		if (0 != i && 1 != i) {
			GetElem_L(L, i - 1, pre_e);
			return OK;
		}
		p=p->next ;
	}
	return ERROR;
}

Status NextElem_L(struct LNode * &L, ElemType cur_e, ElemType &next_e) {

	//要求线性表L存在

	//若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后驱，否则操作失败，next_e无定义
	int i = 0;
	struct LNode *p = L->next;  // p指向第一个结点
	if (NULL != p) {
		i = LocateElem_L(L, cur_e);
		if (i < ListLength_L(L)) {
			GetElem_L(L, i + 1, next_e);
			return OK;
		}
		p = p->next;
	}
	return ERROR;
}

Status ListInsert_L(struct LNode * &L, int i, ElemType e) {
	//在带头结点的单链表L中的第i个位置之前插入元素e
	struct LNode *p = L;
	int j = 0;
	while ( p&&j < i - 1) {//寻找第i-1个结点
		p = p->next;
		++j;
	}
	if (!p || j > i - 1)
		return ERROR;//i小于1或者大于表长加1

	struct LNode *s;
	s= (struct LNode*)malloc(LEN);
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;

}

Status ListDelete_L(struct LNode * &L, int i, ElemType &e) {
	//在带头结点的单链表L 中,删除第i个元素,并由e返回其值
	struct LNode *q,*p = L;
	int j = 0;
	while (p->next&&j < i - 1) {//寻找第i个结点,并令p指向其前驱
		p = p->next;
		++j;

	}

	if (!(p->next) || j > i - 1)//删除位置不合理
		return ERROR;

	q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);

	return OK;

}

Status ListTraverse_L(struct LNode * &L, Status(*visit)(struct LNode * &)) {
	//要求线性表存在

	//依次对L的每个元素调用函数visit(), 一旦visit()失败，则操作失败，返回FALSE,否则返回TRUE



	struct LNode *p;

	p = L->next;   // p指向第一个结点L->next; 

	while (NULL != p) {

		if (ERROR == visit(p))

			return ERROR;

		p = p->next;

	}

	return OK;
}

Status visit_display_L(struct LNode * &L) {

	printf("%d ", L->data);

	return OK;

}



void CreateList_L(struct LNode * &L, int n) {
	//算法2.11
	//逆位序输入n个元素的值,建立带头结点的单链表L
	struct LNode *p;
	L = (struct LNode*)malloc(LEN);

	L->next = NULL;//先建立一个带头结点的单链表
	for (int i = n; i > 0; --i) {
		p = (struct LNode*)malloc(LEN);
		scanf("%d", &p->data);
		p->next = L->next;
		L->next = p;
	}

}

void MergeList_L(struct LNode * &La, struct LNode * &Lb, struct LNode * &Lc) {
	//算法2.12
	//已知线性表La和Lb中的数据元素按值非递减排列
	//归并La和Lb得到新的线性表Lc,Lc的数据元素也按值非递减排列
	struct LNode *pa, *pb,*pc;
	pa = La->next;
	pb = Lb->next;
	Lc = pc = La;//用La的头结点作为Lc的头结点
	while (pa&&pb) {
		if (pa->data <= pb->data) {
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else {
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}

		if (NULL == pa)
			pc->next = pb;
		else
			pc->next = pa;		//插入剩余段

		free(Lb);				//释放Lb的头结点
	}

}