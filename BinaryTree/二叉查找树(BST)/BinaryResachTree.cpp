#include<cstdio>
#include<vector>
using namespace std;

struct node {
	int data;
	node *lchild, *rchild;
};


node* newNode(int v);
node* Creat(int data[], int n);
void search(node *root, int e);
void insert(node* &root, int e);
node* findMax(node* root);
node* findMin(node* root);
void deleteNode(node* &root, int e);
void PreOrderTraverse(node* root);
void InOrderTraverse(node* root);
void PostOrderTraverse(node* root);

node* newNode(int v) {
	node* Node = new node;
	Node->data = v;
	Node->lchild = Node->rchild = NULL;
	return Node;
}

node* Creat(int data[], int n) {

	node* root = NULL;//新建根节点root

	for (int i = 0; i < n; i++) {
		insert(root, data[i]);
	}

	return root;
}

void search(node* root, int e) {

	if (root == NULL) {
		printf("search failed\n");
		return;
	}

	if (e == root->data) {
		printf("%d\n", root->data);
	}
	else if (e < root->data) {
		search(root->lchild, e);
	}
	else {
		search(root->rchild, e);
	}

}

void insert(node* &root, int e) {
	if (root == NULL) {
		root = newNode(e);
		return;
	}
	if (e == root->data) {
		return;
	}
	else if (e < root->data) {
		insert(root->lchild, e);
	}
	else {
		insert(root->rchild, e);
	}
}
//寻找以root为根节点的树中的最大权值结点
node* findMax(node* root) {
	while (root->rchild != NULL) {
		root = root->rchild;
	}
	return root;
}
//寻找以root为根节点的树中的最小权值结点
node* findMin(node* root) {
	while (root->lchild != NULL) {
		root = root->lchild;
	}
	return root;
}
void deleteNode(node* &root, int e) {

	if (root->data == NULL)	return;
	if (root->data == e) {
		if (root->lchild == NULL&&root->rchild == NULL) {
			root = NULL;
		}
		else if (root->lchild != NULL) {//左子树不为空
			node* pre = findMax(root->lchild);//找root前驱
			root->data = pre->data;
			deleteNode(root->lchild, pre->data);
		}
		else {//右子树不为空时
			node* next = findMin(root->rchild);//找root后继
			root->data = next->data;
			deleteNode(root->rchild, next->data);
		}
	}
	else if (root->data > e) {
		deleteNode(root->lchild, e);//在左子树中删除e
	}
	else {
		deleteNode(root->rchild, e);//在右子树中删除e
	}

}

void PreOrderTraverse(node* root) {
	if (root) {
		printf("%d\t", root->data);
		PreOrderTraverse(root->lchild);
		PreOrderTraverse(root->rchild);
	}
}
void InOrderTraverse(node* root) {
	if (root) {
		InOrderTraverse(root->lchild);
		printf("%d\t", root->data);
		InOrderTraverse(root->rchild);
	}
}
void PostOrderTraverse(node* root) {
	if (root) {
		PostOrderTraverse(root->lchild);
		PostOrderTraverse(root->rchild);
		printf("%d\t", root->data);
	}
}

int main() {
	
	int n;
	int data[10];
	
	node* root = NULL;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
		
	}

	root = Creat(data, n);
	
	PreOrderTraverse(root);
	printf("\n");
	InOrderTraverse(root);
	printf("\n");
	PostOrderTraverse(root);
	printf("\n");

	search(root, 5);
	deleteNode(root, 5);

	PreOrderTraverse(root);
	printf("\n");
	InOrderTraverse(root);
	printf("\n");
	PostOrderTraverse(root);
	printf("\n");

	insert(root, 5);

	PreOrderTraverse(root);
	printf("\n");
	InOrderTraverse(root);
	printf("\n");
	PostOrderTraverse(root);
	printf("\n");

	return 0;
}

