#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
卡特兰数的通项是C(2n, n)/(n+1)

注意组合数学中的运算：A(m, n) = m! / (m-n)!    C(m, n) = A(m, n) / n! = m! / ((m-n)!*n!)
因此卡特兰数的通项：
 Cn>>>C(2n, n)/(n+1) = (2n!) / ((2n - n)! * n!)  / (n + 1) = (2n!) / (n! * n!) / (n + 1)

 
 Catalan numbers (1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 2674440, 9694845, ...)
**/


int main()
{
	int i, j, N;
	double sum, num, s;
	while (scanf("%d", &N) != EOF && N!=0 && N<=1000)
	{
		sum = 1,s=1;		//切记数的初始化，为了重新计数也为了计算准确
		for (double i = 1; i <=N; i++)
		{
			sum *= i;
		}
		for (double j = 1; j <= 2 * N;  j++)
		{
			s *= j;
		}
			
//		printf("%.0lf\n", s);
		num = s / (sum*sum) / (N + 1);
		printf("C%d = %.0lf\n",N, num);
	}
	return 0;
}
