#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
***************************************************

	求n个数的最小公倍数。
	入包含多个测试实例，每个测试实例的开始是一个正整数n，
	然后是n个正整数。

***************************************************
*/
int GCD(int x, int y)	//求两个数的最大公约数
{
	int temp;
	while (x%y)
	{
		temp = y;
		y = x%y;
		x = temp;
	}
	return y;
}


int main()
{
	int N, lcm, gcd, a[100];
	while (scanf("%d", &N) != EOF)
	{
		lcm = 1;
		if (N == 0)		break;
		for (int i = 0; i<N; i++)
			scanf("%d", &a[i]);
		for (int i = 0; i < N; i++)
		{
			lcm = lcm / GCD(lcm, a[i])*a[i];
		//	printf("-->%d\n", lcm);
		}
			
		printf("%d\n", lcm);
	}

	return 0;
}