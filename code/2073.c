#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
第一个数是正整数N（≤100）。代表数据的组数。
每组数据由四个非负整数组成x1，y1，x2，y2；所有的数都不会大于100。

输出两点(x1,y1),(x2,y2)之间的折线距离。注意输出结果精确到小数点后3位。
**/
double ans(int x, int y);
int main()
{
	int N, x1, y1, x2, y2;
	double dist;
	while (scanf("%d", &N) == 1)
	{
		while (N--)
		{
			dist = 0;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			dist = fabs(ans(x1, y1) - ans(x2, y2));
			printf("%.3lf\n", dist);
		}
	}
	return 0;
}

double ans(int x, int y)
{
	double t = sqrt((double) 2);	//(double) n 强制类型转换
	double sum = 0;
	int i;
	for (i = 1; i<x + y; i++)
		sum += t*i;		//计算(x,0)与(0,x)的直线长度
	sum += t*x;			//补上(0,x+1)与(x,y)反相直线那段
	for (i = 0; i<x + y; i++)
		sum += sqrt((double) (i*i + (i + 1)*(i + 1)));	//计算(x,0)与(0,x+1)的直线长度
	return sum;
}