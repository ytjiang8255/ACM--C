#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

int main(void)
{
	int M = 0, N = 0, i = 0, j = 0, a = 0, sum = 0;
	while (scanf("%d", &N) != EOF)

	{
		for (i = 0; i<N; i++)
		{
			sum = 0;
			scanf("%d", &M);
			for (j = 0; j < M; j++)
			{
				scanf("%d", &a);
				sum += a;
			}
			if (i<N-1)
				printf("%d\n\n", sum);
			else 
				printf("%d\n", sum);
		}
	}
	
	
	
	return 0;
}