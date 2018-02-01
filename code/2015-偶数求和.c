#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
有一个长度为n(n<=100)的数列，该数列定义为从2开始的递增有序偶数，
现在要求你按照顺序每m个数求出一个平均值，如果最后不足m个，则以实际数量求平均值。编程输出该平均值序列。
输入	数据有多组，每组占一行，包含两个正整数n和m，n和m的含义如上所述。
输出一个平均值序列，每组输出占一行。

3 2
4 2
------
3 6
3 7
**/
int main(void)
{
	int n, m, i, j, sum, count;
	int a[101], b[101];
	while (scanf("%d", &n) == 1 )
	{
		sum = 0;
		count = 0;
		j = 0;
		scanf("%d", &m);
		for (i = 1; i <= n; i++)
			a[i] = 2 * i;
		for (i = 1; i <= n; i++)
		{
			count++;
			sum += a[i];
			if (count == m)
			{
				b[j++] = sum / m;
				sum = 0;
				count = 0;
			}
		}
		if (n%m != 0)
		{
			b[j] = sum / (n%m);
			j++;
		}
		for (i = 0; i<j - 1; i++)
			printf("%d ", b[i]);
		printf("%d\n", b[j - 1]);

	}
	return 0;
}
