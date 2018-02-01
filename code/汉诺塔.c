#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
求把圆盘从下面开始按大小顺序重新摆放在另一根柱子上需要移动多少次。
并且规定，在小圆盘上不能放大圆盘，在三根柱子之间一次只能移动一个圆盘。
即f（n）=2*f（n-1）+1 

**/
long long Change(int num);
int main()
{
	int N;
	long long count;
	while(scanf("%d",&N)==1 && N)
	{
		count=Change(N);
		printf("%lld\n",count);		//注意总变换数的取值范围
		
	}
	return 0;
}


long long Change(int num)
{
	int a;
	if(num==1)
		a=1;
	else
		a=2*Change(num-1)+1;	//汉诺塔变换规律公式
	
}