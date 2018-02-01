#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
***************************************************

输入数据包含多个测试实例,每个测试实例占一行,
由一个整数n组成，(0<n<40)。。
请输出铺放方案的总数，每个实例的输出占一行。

***************************************************
*/
int main()
{
	int n;
	long long int a[42];
	while(scanf("%lld",&n) != EOF)
	{
		a[1]=3;
		a[2]=8;
		a[3]=14;
		for(int i=4;i<=40;i++)
			a[i] =(a[i-1] +a[i-2])*2;
		
		printf("%lld",a[n]);
		
	}
	
	return 0;
}