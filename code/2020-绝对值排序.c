#include <stdio.h>
#include <math.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
****************************************

输入n(n<=100)个整数，
按照绝对值从大到小排序后输出。
题目保证对于每一个测试实例，
所有的数的绝对值都不相等。


****************************************
*/
int main()
{
	int N,a[100],b[100];
	while(scanf("%d",&N)!=EOF)
	{
		if (N==0)	break;
		for (int i=0;i<N;i++)
			scanf("%d",&a[i]);
		
		
		//*********冒泡排序法*********
		int temp;
		for (int i = 0; i < N-1; i++)
		for (int j = 0; j<(N - 1 - i);j++)
		{
			//按绝对值大小值从大到小排序
			if (abs(a[j])<abs(a[j+1]))
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1]= temp;
			}
			
		}
		//取绝对值
//		for (int j = 0; j < N; j++)
//		{
//			if (a[j] < 0)
//				b[j] = -a[j];
//			else b[j] = a[j];
//			printf("%d ", b[j]);
//		}
		//冒泡排序法
//		int temp;
//		for (int i = 0; i < N-1; i++)
//		for (int j = 0; j<(N - 1 - i);j++)
//		{
//			if (b[j]<b[j+1])
//			{
//				temp = b[j];
//				b[j] = b[j+1];
//			b[j+1]= temp;
//			}
			
//		}
		
		//*******两个数之间有空格*******	
		for (int j = 0; j<N; j++)
		{
			printf("%d", a[j]);
			if (j<N-1)
				printf(" ");
		}
		printf("\n");

	}
	
	return 0;
}