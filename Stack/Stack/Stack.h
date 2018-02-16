/**********************************

*                                 *

* 文件名: Stack.h                  *

*                                 *

* 内  容:  顺序栈的基本操作函数声明    *

*                                 *

**********************************/


#include"Status.h"

#define STACK_INIT_SIZE 100		//存储空间初始分配量

#define STACKINCREMENT 10		//存储空间分配增量

typedef  int SElemType;

typedef  int Status;



typedef  struct {

	SElemType *base; //基指针

	SElemType *top;  //指向栈顶的指针

	int stacksize;   //当前栈的最大容量

}SqStack;

Status InitStack(SqStack &S);

Status DestroyStack(SqStack &S);

Status ClearStack(SqStack &S);

Status StackEmpty(SqStack S);

int StackLength(SqStack S);

Status GetTop(SqStack S, SElemType &e);

Status Push(SqStack &S, SElemType e);

Status Pop(SqStack &S, SElemType &e);

Status StackTraverse(SqStack S, Status(*visit)(SElemType));

Status visit_display(SElemType e);

Status display_char(SElemType e);