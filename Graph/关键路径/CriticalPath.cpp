#include"CriticalPath.h"

Graph_DG::Graph_DG(int vexnum, int edge) {
	/*
	初始化一些基本的信息，
	包括边和顶点个数，各个顶点入度数组，邻接表的等
	*/
	this->vexnum = vexnum;
	this->edge = edge;
	this->arc = new Vnode[this->vexnum];
	this->indegree = new int[this->vexnum];
	this->ve = new int[this->vexnum];
	this->vl = new int[this->vexnum];
	for (int i = 0; i < this->vexnum; i++) {
		this->indegree[i] = 0;
		this->ve[i] = 0;
		this->arc[i].firstarc = NULL;
		this->arc[i].data = "v" + to_string(i + 1);
	}
}

//释放内存空间
Graph_DG::~Graph_DG() {
	ArcNode * p, *q;
	for (int i = 0; i < this->vexnum; i++) {
		if (this->arc[i].firstarc) {
			p = this->arc[i].firstarc;
			while (p) {
				q = p->next;
				delete p;
				p = q;
			}
		}
	}
	delete[] this->arc;
	delete[] this->indegree;
}
//判断我们每次输入的的边的信息是否合法
//顶点从1开始编号
bool Graph_DG::check_edge_value(int start, int end, int weight) {
	if (start<1 || end<1 || start>vexnum || end>vexnum || weight < 0) {
		return false;
	}
	return true;
}

void Graph_DG::createGraph() {
	cout << "请输入每条边的起点和终点的编号（顶点从1开始编号）以及每条边的权重" << endl;
	int count = 0; //记录初始化边的条数
	int start, end, weight;
	while (count != this->edge) {
		cin >> start >> end >> weight;
		while (!check_edge_value(start, end, weight)) {
			cout << "输入的信息不合法，请重新输入：" << endl;
			cin >> start >> end >> weight;
		}
		ArcNode * temp = new ArcNode;
		temp->start = start - 1;
		temp->end = end - 1;
		temp->weight = weight;
		temp->next = NULL;
		//如果当前顶点的还没有边依附时，
		++indegree[temp->end];   //对应的弧头的顶点的入度加1
		if (this->arc[start - 1].firstarc == NULL) {
			this->arc[start - 1].firstarc = temp;
		}
		else {
			ArcNode * now = this->arc[start - 1].firstarc;
			while (now->next) {
				now = now->next;
			}//找到该链表的最后一个结点
			now->next = temp;
		}
		++count;
	}
}
void Graph_DG::print() {
	cout << "图的邻接表为：" << endl;
	int  count = 0;
	while (count != this->vexnum) {
		cout << this->arc[count].data << " ";
		ArcNode * temp = this->arc[count].firstarc;
		while (temp) {
			cout << "<"
				<< this->arc[temp->start].data
				<< ","
				<< this->arc[temp->end].data
				<< ">="
				<< temp->weight
				<< " ";
			temp = temp->next;
		}
		cout << "^" << endl;
		++count;
	}
}

bool Graph_DG::topological_sort() {
	cout << "图的拓扑序列为：" << endl;
	stack<int> s; //保存入度为0的顶点下标
	ArcNode * temp;
	int i;
	for (i = 0; i < this->vexnum; i++) {
		if (!indegree[i]) s.push(i); //入度为0 ，则入栈
	}
	//count用于计算输出的顶点个数
	int count = 0;
	while (!s.empty()) {//如果栈为空，退出循环
		i = s.top(); //i等于栈顶的元素
		s.pop();
		cout << this->arc[i].data << " ";//输出拓扑序列
		temp = this->arc[i].firstarc;
		this->List.push(i);
		while (temp) {
			if (!(--indegree[temp->end])) {//如果入度减少到为0，则入栈
				s.push(temp->end);
			}
			//同时更新ve的值
			if ((ve[i] + temp->weight) > ve[temp->end]) {
				ve[temp->end] = ve[i] + temp->weight;
			}
			temp = temp->next;
		}
		++count;
	}
	if (count == this->vexnum) {
		cout << endl;
		return true;
	}
	cout << "此图有环，无拓扑序列" << endl;
	return false;//说明这个图有环
}

bool Graph_DG::CriticalPath() {

	if (!this->topological_sort()) {
		cout << "此图有环，无关键路径" << endl;
		return false;
	}
	cout << "图的关键路径为：" << endl;
	//初始化vl的值都为ve[this->vexnum-1]
	int k;

	for (k = 0; k < this->vexnum; k++) {
		vl[k] = ve[this->vexnum - 1];

	}

	ArcNode * temp;
	while (!this->List.empty()) {
		k = List.top();//从逆拓扑排序开始，求vl
		List.pop();
		temp = this->arc[k].firstarc;
		while (temp) {
			//dut<k,temp->end>，从以第k个顶点为弧尾集合中选择一个最小的值
			//来作为第i个顶点的最迟发生时间
			if (vl[k] > (vl[temp->end] - temp->weight)) {
				vl[k] = vl[temp->end] - temp->weight;
			}
			temp = temp->next;
		}
	}
	int ee;
	int el;
	for (k = 0; k < this->vexnum; k++) {
		temp = temp = this->arc[k].firstarc;
		while (temp) {
			ee = ve[k];
			el = vl[temp->end] - temp->weight;
			if (ee == el) {//这两个值相等，说明它为关键活动：
				cout << this->arc[k].data
					<< "----"
					<< this->arc[temp->end].data
					<< "="
					<< temp->weight
					<< endl;
			}
			temp = temp->next;
		}
	}
}
