#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
	****************************************
	
	输入数据有多组，每组占一行，每行的开始是一个整数n，
	表示这个测试实例的数值的个数，跟着就是n个整数。n=0表示输入的结束，不做处理。
	输出交换后的数列，每组输出占一行。
	4 2 1 3 4
	5 5 4 3 2 1
	0
	-----------
	1 2 3 4
	1 4 3 2 5
	****************************************
*/

int main(void)
{
	int i, N, a[100], Index, temp;
	while (scanf("%d", &N) != EOF && N)
	{
		temp = 0;
		for (i = 0; i<N; i++)
			scanf("%d", &a[i]);

		Index = 0;			//Index是标记比较位置信息
		for (i = 0; i<N; i++)
		{
			if (a[Index]>a[i])
				Index = i;	//和记录下的数据进行交换

		}

		temp = a[Index];
		a[Index] = a[0];
		a[0] = temp;

		for (i = 0; i<N; i++)
		{
			printf("%d", a[i]);
			if (i<N - 1)		//利用i的性质 输出空格
				printf(" ");
		}
		printf("\n");

	}
	return 0;
}
