#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
一个偶数拆成两个不同素数的和，有几种拆法呢？
输入包含一些正的偶数，其值不会超过10000，个数不会超过500，若遇0，则结束。
输出其拆成不同素数的个数，每个结果占一行。
30
26
0
--------
3
2

**/


int IsPrime(int num);
int main()
{
	int N,i,j,count;
	while(scanf("%d",&N)==1&& N)
	if(N%2==0)			//偶数才进入程序测试
	{
		count=0;
		for(i=2;i<=N/2;i++)
		{
			//一个偶数拆成两个不同素数的和
			if(IsPrime(i) && IsPrime(N-i))
			{
				count++;
				if(i==N-i)		//如果两个素数相同则不累加
					count--;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}

int IsPrime(int num)		//素数判定函数，如果是返回值为1，不是则为0
{
	int i;
	for(i=2;i<=num/2;i++)	//从2开始的半值循环判定，一旦有能被整除的数则返回值为0
	if(num%i==0)
		return 0;
	return 1;
	
}