#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告



/*
*******************************************************	
		Input contains an integer N in the first line, 
		and then N lines follow.
		Each line starts with a integer M, 
		and then M integers follow in the same line. 
*******************************************************

*/
int main(void)

{

	int M=0, N=0, i = 0, j = 0, a=0, sum = 0;
	while (scanf("%d", &N) != EOF)

	{
		for (i = 0; i<N; i++)
		{
			sum = 0;
			scanf("%d", &M);
			for (j = 0 ; j < M; j++)
			{
				scanf("%d", &a);
				sum += a;
			}
			printf("%d\n", sum);
		}
//		printf("%d\n", sum);      //[注意！！！]只输出最后一次求和值
	}
	

	
	return 0;
}