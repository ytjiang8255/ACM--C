#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
***************************************************
一条线上有很多灯。 所有这些都是开始的都是off。
在第i个操作中，数字是 i 的倍数的灯改变了条件（打开和关闭到开启）。
每个测试用例在一行中仅包含数字n（0 <n <= 100000）。
在无限操作之后输出第n个灯的条件（0关，1 - 开）。

***************************************************
*/
int main()
{
	int N, i;
	while (scanf("%d", &N) != EOF)		//EOF 的头文件在stdio.h 中 ，如果缺少S“EOF”: 未声明的标识符

	{
			int count = 0;
			for (i = 1; i<=N; i++)		
				//注意 i 不能从0开始 因为除数不能为零！！！
			{
				if (N%i == 0)
					count++;
			}

			if (count % 2 == 0)
				printf("0\n");
			else 
				printf("1\n");

	}
	return 0;
}