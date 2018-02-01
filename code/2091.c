#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
每行包含一个字符和一个整数n(0<n<41)，不同的字符表示不同的花纹，整数n表示等腰三角形的高。
显然其底边长为2n-1。如果遇到@字符，则表示所做出来的样板三角形已经够了。
每个样板三角形之间应空上一行，三角形的中间为空。显然行末没有多余的空格。
X 2
A 7
@
----------
 X
XXX
　
      A
     A A
    A   A
   A     A
  A       A
 A         A
AAAAAAAAAAAAA

**/
int main()			//ERROR 错误的code
{
	int N,i,j,num[42][84],flag=0;
	char a;
	scanf("%c",&a);
	while(a!='@')	//在scanf()中，字符输入不能用EOF判断循环。
	{
		scanf("%d",&N); 
		
		if (flag)		//函数利用flag来实现两个输出之间空一行
			printf("\n");
		flag=1;
		
		if(N==1)
			printf("%c\n",a);
		else
		{
			for(i=1;i<=N-1;i++)		//输出显示前N-1行数据
			{
				for(j=1;j<N+i;j++)	//从N列开始递增输出宽度
				{
					if(j==N-i+1||j==N+i-1)
						printf("%c",a);
					else
						printf(" ");
				}
				printf("\n");
			}	
		}
			
		for(i=0;i<2*N-1;i++)
			printf("%c",a);
		printf("\n");
	}
	return 0;
}
====================================================================

int main()
{
	int N, i, j, flag = 0;
	char a;

	while ( (a=getchar()) != '@')	//在scanf()中，字符输入不能用EOF判断循环。
	{
		scanf("%d%*c", &N);			//排除回车键的影响，否则会导致两个输出之间空了好多行
		if (flag)					//函数利用flag来实现两个输出之间空一行
			printf("\n");
		flag = 1;
		
		if (N == 1)
		{
			for (i = 1; i < N; i++)
				printf(" ");
			printf("%c\n", a);
		}
		else
		{
			for (i = 1; i < N; i++)
				printf(" ");
			printf("%c\n", a);

			for (i = 2; i < N; i++)
			{
				for (j = 1; j <= N - i; j++)
					printf(" ");
				printf("%c", a);
				for (j = 1; j <= 2 * i - 3; j++)
					printf(" ");
				printf("%c\n", a);
			}
		}		

		if (N != 1)
		{
			for (i = 0; i < 2 * N - 1; i++)
//			for (i = 1; i<=2 * N - 1; i++)
				printf("%c", a);
			printf("\n");
		}	

	}
	return 0;
}