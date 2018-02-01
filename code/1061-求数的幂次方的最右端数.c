#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
***************************************************
第一输入是一个整数，T是测试案例的数量。
跟着是T组测试数据。每个测试情形包含一个正整数N（1<=n<=10)。
对于每个测试情形，你应该输出最右边的位数N^N( the rightmost digit of N^N )。

			二分加速(快速幂)
***************************************************
*/
int main()
{
/*	long long int temp,sum, N,a[10000]={0};
	while(scanf("%lld",&N) != EOF)
	{
		for(int i=0;i<N;i++)
		{
			scanf("lld",&a[i]);
			sum=1;
			for(int j=0;j<a[i];j++)
			{
				sum *=a[i];
				temp = sum %10;
			}
			printf("%lld",temp);
		}
		
	}
*/
	long long int temp=1, sum, N, a[10000] = { 0 };
	while (scanf("%lld", &N) != EOF)
	{
		for (int i = 0; i<N; i++)
		{
			scanf("%lld", &a[i]);
			temp = a[i]%10;			//因为最后只是算各位的数值，所以一开始就用个位的数计算
			sum = 1;
//			for (int j = 0; j<=a[i]/2; j++)
			while (a[i])
			{
			//如果a[i]是奇数，就让sum多乘一次temp(而temp=temp%10),以补上temp下面少乘的一次（a[i]%10）
				if (a[i] % 2 == 1)	
				{
					sum = sum*temp % 10;
				}
				temp *= temp;
				temp = temp % 10;
				
			//每一次都把temp*temp赋给temp，然后都把次幂除以 2，这样就是二分加速，就节省了相当多的时间
				a[i] /= 2;	
				
//				printf("%lld.\t", temp);
			}
			printf("%lld\n", sum);
		}

	}

	
	return 0;
}