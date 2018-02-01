#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

int main(void)
{
	int n,sum=1;
	while (scanf("%d",&n) != EOF)
	{
		int i=0; 
		sum=1;
		if (n<30 && n>1)
		{
			for ( i=0;i<n-1;i++)
			{
				sum =2*(sum + 1);
				//分析规律得出算法表达式
			}
			printf("%d\n",sum);
		}	
	}
	return 0;
}