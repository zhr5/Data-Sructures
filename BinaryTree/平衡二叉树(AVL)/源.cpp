#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct node {

	int v, height;//v为结点权值,height为当前子树的高度
	node *lchild, *rchild;
};

node* newNode(int v) {

	node* Node = new node;
	Node->v = v;
	Node->height = 1;
	Node->lchild = Node->rchild = NULL;
	return Node;
}

int getHeight(node* root) {

	if (root == NULL)	return 0;
	return root->height;

}

int getBanlanceFactor(node* root) {

	return getHeight(root->lchild) - getHeight(root->rchild);
}

void updateHeight(node* root) {
	//max(左孩子的height,右孩子的height)+1
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

void search(node* root, int x) {

	if (root == NULL) {
		printf("serach failed\n");
		return;
	}

	if (x == root->v) {
		printf("%d\n", root->v);
	}
	else if (x < root->v) {
		search(root->lchild, x);
	}
	else {
		search(root->rchild, x);
	}
}

//左旋
void L(node* &root) {

	node* temp = root->rchild;//root指向节点A,temp指向结点B
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;

}

//右旋
void R(node* &root) {

	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;

}
//插入权值为v的结点
void insert(node* &root, int v) {

	if (root == NULL) {
		root = newNode(v);
		return;
	}

	if (v < root->v) {//v比根节点的权值小
		insert(root->lchild, v);
		updateHeight(root);
		if (getBanlanceFactor(root) == 2) {
			if (getBanlanceFactor(root->lchild) == 1) {//LL型
				R(root);
			}
			else if (getBanlanceFactor(root->lchild) == -1) {//LR型
				L(root->lchild);
				R(root);
			}
		}
	}
	else {//v比根节点的权值大
		insert(root->rchild, v);
		updateHeight(root);
		if (getBanlanceFactor(root) == 2) {
			if (getBanlanceFactor(root->rchild) == -1) {//RR型
				L(root);
			}
			else if (getBanlanceFactor(root->rchild) == 1) {//LL型
				R(root->rchild);
				L(root);
			}
		}

	}
}

node *Create(int data[], int n) {
	node* root = NULL;
	for (int i = 0; i < n; i++) {
		insert(root, data[i]);
	}

	return root;
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

	
}
