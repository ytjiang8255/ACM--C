#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
***************************************************

输入一个十进制数N，将它转换成R进制数输出。
每个测试实例包含两个整数N(32位整数)和R（2<=R<=16, R<>10）。
以第一个例子 7 2
7%2=1
7/2=3
3%2=1
3/2=1
1%2=1
1/2=0   //结束
结果是111

***************************************************
*/
int main()
{
	long int N, R;
	char str[100];
	while (scanf("%ld%ld", &N, &R) != EOF)
	{

		if (R >= 2 && R <= 16 && R!=10)		//<> 等于 !=
		{
			int i = 0, flag = 0;
			if (N<0)
			{
				flag = -1;
				N = -N;
			}

			while (N>0)
			{
				int temp = N%R;
				if (temp >= 10)	str[i] = temp - 10 + 'A';	//ASCII码减10从A开始计算数值
				else 			str[i] = temp + '0';		//ASCII码从0开始计算数值
				i++;
				N = N / R;

			}

			if (flag == -1)		printf("-");

			for (int j = i - 1; j >= 0; j--)	
				printf("%c", str[j]);
			printf("\n");

		}

	}
	return 0;
}