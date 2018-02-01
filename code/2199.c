//HDOJ-2199    二分查找
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
给定等式8 * x ^ 4 + 7 * x ^ 3 + 2 * x ^ 2 + 3 * x + 6 == Y，可以找到其解在0和100之间;
输入的第一行包含整数T（1 <= T <= 100），表示测试用例数。 
然后T行跟随，每行都有一个实数Y（fabs（Y）<= 1e10）;
输出一个实数（精确到4位小数），这是方程式的解，或者如果0和100之间的方程没有解，则为“无解”！
**/
double Y;
double l, r, m;

double f( double x )
{    
	return 8*pow(x, 4.0) + 7*pow(x, 3.0) + 2*pow(x, 2.0) + 3*x + 6;
}

int main() {
    int t;
    scanf("%d", &t );
    while( t-- ) {
        scanf("%lf", &Y );
        if( f(0) <= Y && Y <= f(100) ) 
		{
            l = 0;
            r = 100;
            while( r - l > 1e-6 ) 
			{
                m = (l + r) / 2;
                double ans = f(m);
                if( ans > Y ) 
                    r = m - 1e-7;
                else
                    l = m + 1e-7;
            }
            printf("%.4lf\n", (l + r) / 2 );
        }
		else
            printf("No solution!\n");
    }
}