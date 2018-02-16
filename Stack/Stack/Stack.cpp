/**********************************

*                                 *

* 文件名: Stack.cpp                *

*                                 *

* 内  容:  顺序栈的基本操作函数实现    *

*                                 *

**********************************/

#include"Status.h"
#include"Stack.h"
#include<stdio.h>
#include<stdlib.h>

Status InitStack(SqStack &S) {

	S.base = (SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if (!S.base)	exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return	OK;

}

Status DestroyStack(SqStack &S) {

	free(S.base);
	S.stacksize = 0;
	S.top = S.base = NULL;
	return OK;

}

Status ClearStack(SqStack &S) {

	S.top = S.base;

	return 0;
}

Status StackEmpty(SqStack S) {

	return (S.base == S.top) ? YES : NO ;
}

int StackLength(SqStack S) {

	return (S.top - S.base);
}

Status GetTop(SqStack S, SElemType &e) {

	if (StackEmpty(S))	return ERROR;
	e = *(S.top - 1);
	return OK;
}

Status Push(SqStack &S, SElemType e) {
	if (S.top - S.base >= S.stacksize) {
		S.base = (SElemType*)realloc(S.base, 
			(S.stacksize + STACKINCREMENT)*sizeof(SElemType));
		if (!S.base)	exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;

	}
	*S.top++ = e;
	return OK;

}

Status Pop(SqStack &S, SElemType &e) {
	if (S.top == S.base)	return ERROR;
	e = *--S.top;
	return OK;
}

Status StackTraverse(SqStack S, Status(*visit)(SElemType)) {
	SElemType *p;

	p = S.base;   //p指向栈底

	while (p != S.top) {  //遍历栈的元素

		visit(*p);

		p++;

	}

	return OK;
}

Status visit_display(SElemType e) {
	printf("%d ", e);

	return OK;
}

Status display_char(SElemType e) {
	printf("%c ", e);

	return OK;
}

int main() {
	SElemType j;
	SqStack s;
	SElemType e;

	if (InitStack(s) == OK)
		for (j = 1; j <= 12; j++)
		{
			Push(s, j);
		}
	printf("栈中的元素依次为：");
	StackTraverse(s, visit_display);
	Pop(s, e);
	printf("弹出的栈顶元素 e=%d\n", e);
	printf("栈空否：%d(1：是 0：否)\n", StackEmpty(s));
	GetTop(s, e);
	printf("栈顶元素 e=%d 栈的长度为%d\n", e, StackLength(s));
	ClearStack(s);
	printf("清栈后，栈空否：%d(1：空 0：否)\n", StackEmpty(s));
	DestroyStack(s);
	printf("销毁栈后， s.stacksize=%d\n", s.stacksize);
	return 0;
}