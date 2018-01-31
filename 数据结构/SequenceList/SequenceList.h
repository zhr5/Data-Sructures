
/**********************************
*                                *
* 文件名: SquenceList.h           *
*                                *
* 内  容: 线性表的基本操作函数声明    *
*                                *
**********************************/
#include"Status.h"

typedef  int ElemType;
typedef  int Status;

//------线性表的动态分配存储结构-------//
#define LIST_INT_SIZE  100  //线性表的存储空间的初始分配量
#define LISTINCREMENT  10   //线性表存储空间的分配增量

typedef struct  {
	ElemType *elem; //存储空间基址
	int length;     //当前长度
	int listsize;   //当前分配存储容量(sizeof(ElemType)为单位)
}SqList;

/*************函数声明****************/

Status InitList(SqList &L);

Status DestoryList(SqList &L);

Status ClearList(SqList &L);

bool ListEmpty(SqList L);

int ListLength(SqList L);

ElemType GetElem(SqList L, int i, ElemType &e );

int LocateElem(SqList L, ElemType e);

ElemType PriorElem(SqList L, ElemType current_e, ElemType &pre_e);

ElemType NextElem(SqList L, ElemType current_e, ElemType &next_e);

Status ListInsert(SqList &L, int i, ElemType e);

ElemType ListDelete(SqList &L, int i, ElemType &e);

Status ListTraverse(SqList L);

void Union(SqList &La, SqList Lb);

void MergeList(SqList La, SqList Lb, SqList &Lc);

/************************************/

