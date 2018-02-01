#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
***************************************************

每个测试实例的输入只包含一个正整数n（1<=n<=30），
表示将要输出的杨辉三角的层数。
对应于每一个输入，请输出相应层数的杨辉三角，
每一层的整数之间用一个空格隔开，每一个杨辉三角后面加一个空行。

***************************************************
*/
int main()
{
	int N,a[30][30];
	while(scanf("%d",&N) != EOF)
	{
		
		for(int i=0;i<N;i++)
		{
			a[i][0]=1;
			a[i][i]=1;
		}
		
		for(int i=2;i<N;i++)
		for(int j=1;j<i;j++)
		{
			a[i][j]= a[i-1][j-1]+a[i-1][j];
		}
		
		for(int i=0;i<N;i++)
		{
			printf("%d",a[i][0]);
			for(int j=0;j<i;j++)
			{
				printf(" %d",a[i][j]);
				
			}
			printf("\n");
		}
		printf("\n");
	}
	
	
//----------------------------------------------------------------------	
	int N, a[50][50] = { 1 };
	while (scanf("%d", &N) != EOF)
	{

		for (int i = 0; i<N; i++)
		for (int j = 0; j<=i; j++)	

		{
			if (j == 0 || j == i)	a[i][j] = 1;
			else a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}

		for (int i = 0; i<N; i++)
		{
			printf("%d", a[i][0]);
			for (int j = 1; j<=i; j++)
			{
//				if (j != 0)	printf(" ");
				printf(" %d", a[i][j]);

			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}