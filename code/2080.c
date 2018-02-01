#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
在一个平面内有两个点，求两个点分别和原点的连线的夹角的大小。
注：夹角的范围[0，180]，两个点不会在圆心出现。
输入:		数据的第一行是一个数据T，表示有T组数据。
每组数据有四个实数x1,y1,x2,y2分别表示两个点的坐标,这些实数的范围是[-10000,10000]。

输出:		夹角的大小精确到小数点后两位。
2
1 1 2 2
1 1 1 0
--------
0.00
45.00

向量运算法则：
			a*b=|a|*|b|cos(夹角)
			[向量计算---横坐标*横坐标 + 纵坐标*纵坐标]
			(x1,y1)*(x2,y2)=sqrt(x1*x1+y1*y1)*sqrt(x2*x2+y2*y2)cos(夹角)
			
**/


#define PI 3.141592653

int main()
{
	int T;
	double x1,x2,y1,y2,t1,t2;
	while(scanf("%d",&T)==1)
	{
		while(T--)
		{
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			t1=x1*x2+y1*y2;
			t2=sqrt((x1*x1+y1*y1)*(x2*x2+y2*y2));
		
			printf("%.2lf\n",acos(t1/t2)/PI*180);	//acos() --> math.h
		}
	}
	return 0;
}
