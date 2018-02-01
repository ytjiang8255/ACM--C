#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
***************************************************

每个实例占一行，由两个正整数A和B组成（1<=A,B<=10000），
如果A=0, B=0，则表示输入数据的结束，不做处理。
对于每个测试实例，请输出A^B的最后三位表示的整数，每个输出占一行。

题中数据岛后面会很大，所以当它大于100000时我们可以截取后面的几位，
使得数据不会爆炸掉
***************************************************
*/

int power1(int a, int n)
{
	int temp;
	if (n == 0)	
		temp = 1;
	else
	{
		temp = power1(a*a, n / 2);
		if (n % 2 == 1)
			temp *= a;
	}
	
	return temp;
}

int power2(int a, int n)
{
	int ans = 1;
	while (n)
	{
		if (n & 1)
			ans *= a;
		a *= a;
//		printf("n=%d.\ta=%d\tans=%d\n", n, a, ans);
		n >>= 1;
		
	}
//	printf("ans=%d.\t", ans);
	return ans;
}


int main()
{
	int N=0, temp = 1, sum=0, a[10000] = { 0 };
	int M;
	while (scanf("%d", &M) != EOF)
	{
		for (int i = 0; i<M; i++)
		{
			scanf("%d%d", &a[i],&N);
			sum = power1(a[i], N);
			printf("%d\n", sum);
//			sum = power2(a[i], N);
//			printf("\n%d\n", sum);
		}

	}

	return 0;
}



//=================================================================



int main()
{
	int a, b, c = 1;
	while (scanf("%d%d", &a, &b) != EOF)
	{
		c = 1;
		if (a == 0 && b == 0)	break;
		if (a<=1 || b>=10000)
			printf("%d\n", c);
		else
		{
			for (int i = 0; i<b; i++)
			{
				c = (c*a) % 1000;
//				printf("%d\t", c);
			}

			printf("%d\n", c);

		}
		
	}
/*	
		for(int i=0;i<b;i++)
		{
			c *= a;
		}
		printf("%d",c%1000);
		//会溢出，所以通不过
*/
	return 0;
}


