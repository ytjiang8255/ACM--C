#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/*
	*************************************************************
			统计给定的n个数中，负数、零和正数的个数。
	************************************************************

*/
int main(void)
{
	int i, N;
	float a;
	int Positive=0 ,Negative=0,Zero=0;
	while (scanf("%d", &N) != EOF)
	{
//		printf("%d\n",N);
		if (N == 0)
			 break;
		else
		{
			for (i = 0; i < N; i++)
			{
				scanf("%f", &a);
				if (a<0)
					Negative++;
				else if(a==0)
					Positive++;
				else 
					Zero++;
			}
			printf("%d %d %d\n", Negative,Zero,Positive);
		}

	}
	
	return 0;
	
}
