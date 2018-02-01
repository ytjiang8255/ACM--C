#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/**
黄金比例的计算：（n越大越接近1.618的范围）
1/1  2/1  3/2  5/3  8/5  13/8  21/13  34/21 ........

**/

int main()
{
	int i, j, N;
	double sum, num[1000], s[1000] = {0}, x[1000] = { 0 };
	while (scanf("%d", &N) != EOF && N!=0 && N<=1000)
	{
		sum = 0;
		s[0] = 1;
		x[0] = 0;
		num[0] = (sum + s[0]) / (s[0] + x[0]);
		for (i = 1; i <= N; i++)
		{
			s[i] = s[i - 1] + x[i - 1];
			x[i] = s[i - 1];
//			if( (s[i] / x[i] - s[i - 1] / x[i-1])<0.001)
			printf("%.5lf\n", s[i]/x[i]);
		}

	}
	return 0;
}
