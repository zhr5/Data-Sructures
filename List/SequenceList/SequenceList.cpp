
/*************************************
*                                    *
* 文件名: SquenceList.cpp             *
*                                    *
* 内  容: 线性表的基本操作函数具体实现    *
*                                    *
*************************************/


#include"Status.h"
#include"SequenceList.h"
#include<stdio.h>
#include<stdlib.h>

Status InitList(SqList &L) {
	L.elem = (ElemType*)malloc(LIST_INT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INT_SIZE;
	return OK;
}

Status DestoryList(SqList &L) {
	if (L.elem) free(L.elem);
	printf("线性表已销毁!");
	return OK;
}

Status ClearList(SqList &L) {
	L.length = 0;
	printf("线性表已清空!");
	return OK;
}

bool ListEmpty(SqList L) {
	if (0 == L.length)
		return TRUE;
	else
		return FALSE;
}

int ListLength(SqList L) {
	return L.length;
}

ElemType GetElem(SqList L, int i, ElemType &e) {
	if (i<1 || i>L.length)
		printf("i值不合法!");
	else {
		e = *(L.elem + i - 1);
	}
	return e;

}

int LocateElem(SqList L, ElemType e) {//返回的是(下标-1)
	for (int i = 0; i < L.length; i++) {
		if (e == L.elem[i])
			return i;
	}
	return 0;//表示无此元素
}

ElemType PriorElem(SqList L, ElemType current_e, ElemType &pre_e) {
	int i = LocateElem(L, current_e);
	if (i > 0) return L.elem[i - 1];

}

ElemType NextElem(SqList L, ElemType current_e, ElemType &next_e) {
	int i = LocateElem(L, current_e);
	if (i < L.length - 1) return L.elem[i + 1];
}

Status ListInsert(SqList &L, int i, ElemType e) {
	ElemType *p, *q, *newbase;

	if (i<1 || i>L.length + 1) return ERROR;

	if (L.length >= L.listsize) {
		newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase) exit(OVERFLOW);
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}

	q = &(L.elem[i - 1]);

	for (p = &(L.elem[L.length - 1]); p >= q; --p) {
		*(p + 1) = *p;
	}
	*q = e;
	++L.length;
	return OK;

}

ElemType ListDelete(SqList &L, int i, ElemType &e) {
	ElemType *p = NULL, *q = NULL;

	if (i<1 || i>L.length + 1) return ERROR;

	p = &(L.elem[i - 1]);
	e = *q;
	q = L.elem + L.length - 1;
	for (++p; p <= q; ++p) {
		*(p - 1) = *p;
	}

	--L.length;
	return OK;

}

Status ListTraverse(SqList L) {
	int i = 0;
	for (int i = 0; i<L.length; i++) {
		printf("%d ", L.elem[i]);
	}
	return OK;
}
/**************算法2.1 严蔚敏******************/

void Union(SqList &La, SqList Lb) {
	//将所有在Lb中但不在La中的元素插入到La
	int La_len = La.length;
	int Lb_len = Lb.length;
	ElemType e;
	for (int i = 1; i <= Lb.length; i++) {
		GetElem(Lb, i, e);
		if (!LocateElem(La, e))
			ListInsert(La, ++La_len, e);
	}

}
/**************算法2.2  严蔚敏*******************/
void MergeList(SqList La, SqList Lb, SqList &Lc) {
	//已知线性表La和Lb中的数据元素按值非递减排列
	//归并La和Lb得到新的线性表Lc,Lc的数据元素也按值非递减排列
	InitList(Lc);
	int i = 1, j = 1, k = 0;
	int La_len = ListLength(La);
	int Lb_len = ListLength(Lb);
	ElemType ai, bj;

	while ((i <= La_len) && (j <= Lb_len)) {
		GetElem(La, i, ai);
		GetElem(Lb, j, bj);
		if (ai <= bj) {
			ListInsert(Lc, ++k, ai);
			++i;
		}
		else {
			ListInsert(Lc, ++k, bj);
			++j;
		}
	}

	while (i <= La_len) {
		GetElem(La, i++, ai);
		ListInsert(Lc, ++k, ai);
	}

	while (j <= Lb_len) {
		GetElem(Lb, j++, bj);
		ListInsert(Lc, ++k, bj);
	}
}