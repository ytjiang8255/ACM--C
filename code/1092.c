#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/*
	***数列求和***

*/
int main(void)

{
/*	int i,N,  a[i], sum=0;
	scanf("%d",&N);
	
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
		sum += a[i];
		
	}
	printf("\n");
*/	
	int i, N, a, sum = 0;
	while (scanf("%d", &N) != EOF)  	
		//ACM库常用是的输入技巧
	{
//		printf("%d\n",N);
		if (N == 0)
			 break;
		else
		{
			for (i = 0; i < N; i++)
			{
				scanf("%d", &a);
				sum += a;
			}
			printf("%d\n", sum);
			sum = 0;
		}

	}
	if (sum != 0)
		printf("%d\n", sum);
	
	return 0;
}