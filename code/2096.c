#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
对于大于等于100的整数, 小明仅保留该数的最后两位进行计算, 
如果计算结果大于等于100, 那么小明也仅保留计算结果的最后两位.
输入数据的第一行为一个正整数T, 表示测试数据的组数. 然后是T组测试数据.
每组测试数据包含两个非负整数A和B(A和B均在int型可表示的范围内).
输出小明A+B的结果.
**/
int main()
{
	int T,a,b;
	while(scanf("%d",&T)==1)
	while(T--)
	{
		scanf("%d%d",&a,&b);
		a=a%100;
		b=b%100;
		printf("%d\n",(a+b)%100);
	}
	return 0;
}
