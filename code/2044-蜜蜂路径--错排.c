#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
***************************************************

输入数据的第一行是一个整数N,表示测试实例的个数，
然后是N 行数据，每行包含两个整数a和b(0<a<b<50)。

请输出蜜蜂从蜂房a爬到蜂房b的可能路线数，每个实例的输出占一行

***************************************************
*/
int main()
{
	int N, x, y;
	long long int a[52];		//!!!注意数组的溢出
	while (scanf("%d", &N) != EOF)
	{
		
//		if ((x >= 1 && x<50 )|| (y >= 1 && y<50))
		for (int i = 0; i<N; i++)
		{
			{
				a[1] = 1;
				a[2] = 2;
				a[3] = 3;
				for (int j = 4; j <= 50; j++)
				{
					a[j] = a[j - 1] + a[j - 2];
				}
			}
			scanf("%d%d", &x, &y);
			printf("%lld\n", a[y - x]);

		}

	}
	return 0;
}