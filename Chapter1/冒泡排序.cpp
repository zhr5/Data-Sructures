#include <iostream>
using namespace std;

void  swap(int &a,int &b){
	int temp;
	temp=a;
	a=b;
	b=temp;
}

void bubblesort1A(int A[],int n){//起泡算法版本1A:0<=n
	bool sorted =false;//整体排序标志
	while(!sorted){
		sorted=true;//假定已经排序
		for(int i=0;i<n;i++){
			if(A[i-1]>A[i]){
				swap(A[i-1],A[i]);
				sorted=false;
			}
		} 
		n--;//至此元素必然就位 
	} 
	
} 
int main(int argc, char** argv) {
	int A[7]={5,2,7,4,6,3,1};
	bubblesort1A(A,7);
	for(int i=0;i<7;i++){
		cout<<A[i]<<" ";
	}
	return 0;
}
