#include <stdio.h>
#include <math.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/*
	*************************************************************
			1 - 1/2 + 1/3 - 1/4 + 1/5 - 1/6 + ...
			现在请你求出该多项式的前n项的和。
	*************************************************************
*/
	
int main(void)
{
/*	int i,M,a,N;
	while (scanf("%d",&M) != EOF)
	{
		for (i=0;i<M;i++)
		{
			scanf("%d",&a);
			if (a == 1)
				printf("%d\n",A);
			else 
			{
				for (int j=0;j<a;j++)
				{
					if (j%2 ==0)
						A += (-1/j);
					else A += (1/j)
				}
				printf("%d\n",A);
			}
		}
*/
	double sum;
	int i, M, a, N;
	while (scanf("%d", &M) != EOF)
	{
		for (i = 0; i<M; i++)
		{
			sum = 0;
			scanf("%d", &a);
			if (a == 1)
				 sum += 1;
			else
			{
				sum = 1;
				for (int j = 2; j<=a; j++)
				{
					if (j % 2 == 0)
						sum += (-1.0 / j);
					else sum += (1.0 / j);
				}
			//	printf("%.2lf\n", sum);
			}
			printf("%.2lf\n", sum);
		}

	}
	
	}
	
	return 0;
	
}