#include <stdio.h>
#include <math.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/*
	*************************************************************
	输入两点坐标（X1,Y1）,（X2,Y2）,计算并输出两点间的距离。
	************************************************************

*/
int main(void)
{
	double x1, x2, y1, y2, dis;   
	//因为sqrt（）只能用于double型数据类型
	while (scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2) != EOF)
	{
	//	如果加了double ，编译器提示类型错误  
	//	dis = double sqrt(double((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1)));
		dis =  sqrt(((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1)));
		printf("%.2lf\n", dis);	//两位小数输出
	}
	return 0;
	
}


