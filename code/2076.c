#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
输入数据的第一行是一个数据T，表示有T组数据。
每组数据有三个整数h(0 <= h < 24)，m(0 <= m < 60)，s(0 <= s < 60)分别表示时、分、秒。

输出夹角的大小的整数部分。
**/
#define r 6.0
#define Ri 30.0
int main()
{
	int T;
	float hour,min,sec,k=1/10;
	while(scanf("%d",&T)==1)
	{
		while(T--)
		{
			scanf("%f%f%f",&hour,&min,&sec);
			if(hour>=12)
				hour-=12;
			min=min*r+sec*k;
			hour=hour*Ri+min*k;
		//	printf("%.2lf  %.2lf",hour,min);
			if((hour-min)>180)
				printf("%.0f\n",360-fabs(hour-min));
			else 
				printf("%.0f\n",fabs(hour-min));
		}
		
	}
	return 0;
}