#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
该输入包含几个测试用例。 每个测试用例包含上面提到的正整数N（1 <= N <= 120）。 输入结束文件结束。
对于每个测试情形，输出行包含一个整数p的方程有不同的发现
给定一个正整数N，我们定义一个这样的公式：
  N = A [1]+ A [2]+[3] +... + A [M]
  A [1]>0, 1<= M<= N;

**/

int main()
{
	int N, a[121], b[121];
	while (scanf("%d", &N) == 1 && N != 0)
	{
		for (int i = 0; i <= N; i++)
		{
//			a[i] = i;
			a[i] = 1;		//系数都是为 1
			b[i] = 0;		//b[0,1,2....,N]均为整形数，而超过N后则是随机数！！！
		}

		for (int i = 2; i <= N; i++)		//第一项的每一个数与第二项的每一数相乘
		{
			for (int j = 0; j <= N; j++)	//代表i-1项 满足项的系数j<=N 的进行循环，不一定是j-1的每一项
			{
				for (int k = 0; k <= N; k += i)//符合条件的i项
				{
					//i-1项的每一个符合条件的与i项相乘，b[k+j]->取系数  a[j]->ax^n 的系数a
					b[j + k] += a[j];		
					printf("b[%d] = %d    a[%d]= %d\n", j + k, b[j + k], j, a[j]);
				}
				printf("i: %d      j: %d\n\n", i, j);
			}

			//每当j=4之后 要重新给a[i]赋值，这样每次内循环可以计算出母函数的数值
			for (int k = 0; k <= N; k++)
			{
				a[k] = b[k];		//把i与i-1项的乘积从临时 b数组保存到 a数组中等待i+1与 b数组的乘积
				b[k] = 0;			//b[i]数组全部清零 重新进行相关计算赋值
			}

		}
		printf("%d\n", a[N]);
	}
	
	return 0;
}