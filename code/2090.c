#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
输入含有一些数据组，每组数据包括菜种（字串），数量（计量单位不论，一律为double型数）
单价（double型数，表示人民币元数），每组数据的菜价就是数量乘上单价啊。
菜种、数量和单价之间都有空格隔开的。
由于最小支付单位是角，所以总是在支付的时候采用四舍五入的方法把分头去掉。
最后，请输出一个精度为角的菜价总量。
青菜 1  2
罗卜 2  1.5
鸡腿 2  4.2
----------
13.4

!!!!!floor(x),有时候也写做Floor(x)，其功能是“向下取整”，或者说“向下舍入”，
即取不大于x的最大整数（与“四舍五入”不同，下取整是直接取按照数轴上最接近要求的值左边的值，也就是不大于要求的值的最大的那个）。
**/
int main()
{
	double num,fare,total=0;
	char str[100];
	while(scanf("%s%lf%lf",str,&num,&fare)!=EOF)
		total+=num*fare;
		printf("%.1lf\n", total);
//	printf("%.1lf\n", floor(total * 10 + 5) / 10);		//计算有误差
	return 0;
}