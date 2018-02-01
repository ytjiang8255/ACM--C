#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
***************************************************

给定三条边，请你判断一下能不能组成一个三角形。

***************************************************
*/
int main()
{
/*	运行超时
	int N,a[2];
	while(scanf("%d",&N) != EOF)
	{
		for(int i=0;i<3;i++)
			scanf("%d",&a[i]);
		if(a[0]+a[1]>a[2] && a[0]+a[2]>a[1] && a[1]+a[2]>a[0])
			printf("YES\n");
		else 	printf("NO\n");
	}
*/
//*****************************************************
	int N;
	float a, b, c;		//注意数据的类型 int型一直显示编译超时
	while (scanf("%d", &N) != EOF)
	{
		a = b = c = 0;
		for (int i = 0; i<N; i++)
		{
			scanf("%f%f%f", &a, &b, &c);
			if (a + b>c && a + c>b && b + c>a)
				printf("YES\n");
			else 	printf("NO\n");
		}
	}

	
	return 0;
}