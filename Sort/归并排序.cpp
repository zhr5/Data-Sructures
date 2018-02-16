#include <stdio.h>
#include <stdlib.h>
#define N 10

void Swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

const int maxn = 100;
//将数组A的[L1,R1]与[L2,R2]区间合并为有序区间(此处L2即为R1+1) 
void merge(int A[],int L1,int R1,int L2,int R2)
{
    int i=L1,j=L2;//i指向A[L1],j指向A[L2]
    int temp[maxn] , index=0;//temp临时存放合并后的数组,index为其下标
    while(i<=R1&&j<=R2)
    {
        if(A[i]<=A[j])
        {
            temp[index++]=A[i++];
        }
        else
        {
            temp[index++]=A[j++];
        }
     } 
     while(i<=R1) temp[index++]=A[i++];
     while(j<R2)  temp[index++]=A[j++];
     for(i=0;i<index;i++)
     {
        A[L1+i]=temp[i];//将合并后的序列赋值回数组A 
     }
 }
 /***********************递归实现********************/ 
void mergeSort(int A[],int left,int right)//将array数组当前区间[left,right]进行归并排序 
 {
    if(left<right)
    {
        int mid=(left+right)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid+1,right);
        merge(A,left,mid,mid+1,right);//将左右子区间合并 
     } 
}
/******************非递归*************************/
/*void mergesort(int A[])
{//step为组内元素个数,step/2为左子区间元素个数,注意等号可以不取 
    for(int step=2;step/2<=N;step*=2)
    {//每step个元素一组,组内前step/2和step/2个元素进行合并 
        for(int i=1;i<=N;i+=step)//对每一组 
        {
            int mid=i+step/2-1;//左子区间元素个数为step/2
            if(mid+1<=N)  //右区间存在元素则合并 
            {//左子区间为[i,mid],右子区间为[ mid+1 , min(i+step-1,N) ] 
                merge(A,i,mid,mid+1,min(i+step-1,N));
             } 
         } 
     } 
 } */  
int main()
 {
	int x, y;
	int A[N];
	
	for (x = 0; x<10; x++) 
	{
			y = rand() % 100;
			A[x] = y;
			printf("%3d\t", y);
		}
		printf("\n");
		mergeSort(A,0,9);
	//	mergesort(A);
		for(int i=0;i<N;i++)
		{
			printf("%d\t",A[i]); 
		}
		printf("\n"); 
		return 0;
	}
