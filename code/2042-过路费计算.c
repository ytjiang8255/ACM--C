#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
***************************************************

输入数据第一行是一个整数N，下面由N行组成，
每行包含一个整数a(0<a<=30),表示收费站的数量。

***************************************************
*/
int main()
{
	int N, a;
	while (scanf("%d", &N) != EOF)
	{
		int sum;
		for (int i = 0; i<N; i++)
		{
			scanf("%d", &a);
			sum = 3;
			for (int j = a; a > 0; a--)
				sum = (sum - 1) * 2;
			printf("%d\n", sum);
		}

	}
	return 0;
}