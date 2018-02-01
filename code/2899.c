//HDOJ-2899    二分查找
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/**
f(x)＝6*X^7+x^8*6*7+x^3+x^5*2*y-x(0<=x<=100)
	找到的最小的值x是在0和100之间。
输入的第一行包含整数T（1 <= T <= 100），表示测试用例数。 
然后T行跟随，每行只有一个实数Y.（0 <Y <1e10）
当x在0到100之间时，只是最小值（精确到4位小数）。
**/
double Y;
double l, r, m;
double f(double x)
{
	return 6 * pow(x, 7.0) + 8 * pow(x, 6.0) + 7 * pow(x, 3.0) + 5 * pow(x, 2) + x*y;
}

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) 
	{
		scanf("%lf", &y);
			l = 0;
			r = 100;
			while (r - l > 1e-6) 
			{
				m = (l + r) / 2;
				n = (m + r) / 2;
				
				if (f(m,y) < f(n,y)) 
					r = n;
				else
					l = m;
				printf("r=%.8lf    l=%.8lf\n", l, r);
			}
			printf("%.4lf\n", f(l,y));
	}
	
	return 0;
}