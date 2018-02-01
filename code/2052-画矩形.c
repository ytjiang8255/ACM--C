#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
***************************************************
输入包含多个测试用例。
有两个数字n和m（0 <n，m <75）表示矩形的宽度和高度。输出EOF的结尾。
对于每种情况，您应该绘制一个宽度和高度给出的矩形。
在每种情况下，你应该是一个空白行。

***************************************************
*/
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m) != EOF)
	{
/*		char a[100][100];
		int i = 0, j = 0;
		if (i == 0 && j == n + 1 && j == 0 && i == m + 1)
			a[i][j] = '+';
		else if ((i == 0 && j != 0) || (i == m + 1 && j != 0))
			a[i][j] = '|';
		else if ((i != 0 && j == 0) || (i != 0 && j == n + 1))
			a[i][j] = '-';
		else a[i][j] = ' ';;

		for (int i = 0; i<m + 2; i++)
		for (int j = 0; j<n + 2; j++)
		{
			printf("%c", a[i][j]);

		}
		printf("\n");
*/
		int i;
		printf("+");
		for (i = 0; i < n ; i++)
			printf("-");
		printf("+\n");

		for (i = 0; i < m ; i++)
		{
			int j;
			printf("|");
			for (j = 0; j < n; j++)
				printf(" ");
			printf("|\n");
		}
		printf("+");
		for (i = 0; i < n; i++)
			printf("-");
		printf("+\n");
		printf("\n");
	}
		
	}
	
	return 0;
	
}