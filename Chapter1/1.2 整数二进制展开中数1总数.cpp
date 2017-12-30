#include<iostream>
using namespace std;

int countOnes(unsigned int n){//统计整数二进制展开中数为1的总数: 复杂度:O(logN)
	int ones=0;//计数位复位
	while(n>0){
		ones+=(1&n);//检查最低位,若为1则计数
		n>>=1;//右移1位 
	} 
	return ones; 
	
}
int main(){
	cout<<countOnes(441)<<endl;
	return 0;
}
