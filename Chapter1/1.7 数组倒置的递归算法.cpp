#include<iostream>
using namespace std;

void  swap(int &a,int &b){
	int temp;
	temp=a;
	a=b;
	b=temp;
}

void reverse(int *A,int low ,int high){//数组倒置(多递归基递归版) 复杂度:O(logN) 
	if(low<high){
		swap(A[low],A[high]);
		reverse(A,low+1,high-1);
	} //else隐含了两种递归基
	 
}

int main(){
	int A[7]={1,2,3,4,5,6,7};
	reverse(A,0,6);
	for(int i=0;i<7;i++){
		cout<<A[i]<<" ";
	}
	return 0;
}
