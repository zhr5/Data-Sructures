#include <stdio.h>

int move_times = 0; 	// 全局变量， 搬动次数

// 第n块圆盘从塔座x 搬到塔座z
void move(char x, int n, char z)
{
	printf("第%i步: 将%i号圆盘从%c移到%c\n", ++move_times, n, x, z);
}

// 将塔座x上按直径由小到大且自上而下编号为1至n的n个圆盘
// 按规则搬到塔座z上，y可以做辅助塔座
void hanoi(int n, char x, char y, char z)
{
	// 出口
	if (1 == n)
	{
		move(x, 1, z);
	}
	else
	{
		hanoi(n-1, x, z, y);	// 将x上编号为1至n-1的圆盘移动y上，z做辅助塔座(降阶递归调用)
		move(x, n, z);			// 将编号为n的圆盘由x移到z上
		hanoi(n-1, y, x, z);	// 将y上编号为1至n-1的圆盘移动x上，x做辅助塔座(降阶递归调用)
	}
}

int main()
{
	int n;
	printf("3个塔座为x，y，z，圆盘最初在x上，借助y座移动z座。请输入圆盘数：");
	scanf("%d", &n);
	hanoi(n, 'x', 'y', 'z');
	return 0;
}

