#include <stdio.h>
#include <math.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/*
	*************************************
			求平方值，立方值
	*************************************

*/
int main(void)
{
	int i, N, a, sum = 1;
	while(scanf("%d",&N) != EOF)
	{
		sum = 1;
		for (i=0;i<N;i++)
		{
			
			scanf("%d",&a);
			if (a %2 ==0)
				sum += a*a;
			else 
				sum += a*a*a；
		}
		printf("%d\n",sum);
	
	}
	
	
	return 0;
}