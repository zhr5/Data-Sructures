#include"tree.h"
#include"Status.h"
#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<queue>
using namespace std;

Status CreateBiTree(BiTree &T) {
	/**

	* 算法6.4，按先序顺序构造二叉树

	*/

		char ch;

		scanf("%c", &ch);

		if (' ' == ch)

			T = NULL;

		else {

			T = (BiTNode *)malloc(sizeof(BiTNode));

			if (!T)

				return ERROR;

			T->data = ch;

			CreateBiTree(T->lchild);	//构造左子树

			CreateBiTree(T->rchild);	//构造右子树

		}

		return OK;
	
}

Status display(TElemType e) {

	printf("%c ", e);

	return OK;
}

/**

* 算法6.1，先序遍历二叉树，对每个元素调用函数viist

*/

Status PreOrderTraverse(BiTree T, Status(*visit)(TElemType e))

{

	if (T) {

		if (OK == visit(T->data))

			if (OK == PreOrderTraverse(T->lchild, visit))

				if (OK == PreOrderTraverse(T->rchild, visit))

					return OK;

		return ERROR;

	}
	else

		return OK;

}

/**

* 中序遍历二叉树，对每个元素调用函数viist

*/

Status InOrderTraverse(BiTree T, Status(*visit)(TElemType e))

{

	if (T) {

		if (OK == InOrderTraverse(T->lchild, visit))

			if (OK == visit(T->data))

				if (OK == InOrderTraverse(T->rchild, visit))

					return OK;

		return ERROR;

	}
	else

		return OK;

}

/**

* 后序遍历二叉树，对每个元素调用函数viist

*/

Status PostOrderTraverse(BiTree T, Status(*visit)(TElemType e))

{

	if (T) {

		if (OK == PostOrderTraverse(T->lchild, visit))

			if (OK == PostOrderTraverse(T->rchild, visit))

				if (OK == visit(T->data))

					return OK;

		return ERROR;

	}
	else

		return OK;

}
/**

* 层序遍历二叉树，利用队列实现

*/
Status LevelOrderTraverse(BiTree T, Status(*visit)(TElemType e)) {
	BiTree p;
	queue<BiTree>Q;
	p = T;
	Q.push(T);

	while (!Q.empty()) {
		p = Q.front();
		Q.pop();
		visit(p->data);
		if (p->lchild != NULL)
			Q.push(p->lchild);
		if (p->rchild != NULL)
			Q.push(p->rchild);
	
	}

	return OK;
}
/**

* 非递归法实现先序遍历二叉树T

*/
Status PreOrderTraverse2(BiTree T, Status(*visit)(TElemType e)) {
	BiTree p = T;
	stack<BiTree> s;
	
	while (p || !s.empty()) {
		while (p) {
			visit(p->data);
			s.push(p);
			p = p->lchild;
		}
		if (!s.empty()) {
			p = s.top();
			s.pop();
			p = p->rchild;
		}
	}
	return OK;
}
/**

* 算法6.3，非递归法实现中序遍历二叉树T

*/
Status InOrderTraverse2(BiTree T, Status(*visit)(TElemType e)) {

	stack<BiTree> S;
	BiTree p;

	S.push(T);

	while (!S.empty()) {

		while (p == S.top() && p) {

			S.push(p->lchild);
		}//while
			p = S.top();
			S.pop();

			if (!S.empty()) {

				p = S.top();
				S.pop();

				if (!visit(p->data))	return ERROR;
				
				S.push(p->rchild);

			}//if

		}//while

	return OK;
}

Status InOrderTraverse3(BiTree T, Status(*visit)(TElemType e)) {

	stack<BiTree> s;
	BiTree p =T;
	while (p || !s.empty()) {
		if (p) {
			s.push(p);
			p = p->lchild;
		}
		else {
			p = s.top();
			s.pop();
			if (!visit(p->data))	return ERROR;
			p = p->rchild;
		}//else
	}//while
	return OK;
}
/**

* 非递归法实现后序遍历二叉树T

*/
Status PostOrderTraverse2(BiTree T, Status(*visit)(TElemType e)) {
	stack<BiTree> s;
	BiTree p = T;
	int Tag[20];//标志栈
	int t = 1;
	while (p || !s.empty()) {
		while (p) {//向左走到尽头
			s.push(p);
			p = p->lchild;
			Tag[t++] = 0;
		}

		while (!s.empty() && 1 == Tag[t - 1]) {
			p = s.top();
			s.pop();
			t--;
			if (ERROR == visit(p->data))
				return ERROR;
		}

		if (!s.empty()) {		//结点标志为0，则访问右子树，并将结点标志置为1
			Tag[t - 1] = 1;
			p = s.top();
			p = p->rchild;
		}
		else
			break;
	}
	return OK;
}


int	main() {
	BiTree T;
	CreateBiTree(T);

	PreOrderTraverse(T,display);
	printf("\n");

	InOrderTraverse(T, display);
	printf("\n");

	PostOrderTraverse(T, display);
	printf("\n");

	LevelOrderTraverse(T, display);
	printf("\n");

	PreOrderTraverse2(T, display);
	printf("\n");

	InOrderTraverse2(T, display);
	printf("\n");

	InOrderTraverse3(T, display);
	printf("\n");

	PostOrderTraverse2(T, display);

	return 0;
}