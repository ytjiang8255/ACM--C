#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
***************************************************

输入数据首先包含一个整数N，表示测试实例的个数，
然后是N行数据，每行包含一个整数M（1<=M<=40）,表示楼梯的级数。
请输出不同走法的数量

***************************************************
*/
int main()
{
	int N,M,a[50];
	while(scanf("%d",&N) != EOF)
	{
		scanf("%d",&M);
		if(M>=1 && M<40)
		for(int i=0;i<N;i++)
		{
			{
				a[1]=0;
				a[2]=1;
				a[3]=2;
				for(int j=4;j<=40;j++)
				{
					a[j]=a[j-1]+a[j-2];
				}
				
				printf("%d\n",a[M]);
				
			}
			
		}
		
	}
	
	return 0;
}