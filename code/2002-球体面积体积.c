#include <stdio.h>
#include <math.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
#define Pi 3.1415927			//注意Pi的取值
/*
	*************************************************************
	求球的体积，注意输出格式！
	************************************************************

*/
int main(void)
{
	double r;
	while (scanf("%lf", &r) != EOF)
	{
//		printf("%.3lf\n", (4 * r*r*r*Pi) / 3);
		printf("%.3lf\n",  r*r*r*Pi*4.0 / 3.0);
	}
	return 0;
}
		