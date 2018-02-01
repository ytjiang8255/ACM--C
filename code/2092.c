#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
输入数据为成对出现的整数n，m（-10000<n,m<10000），它们分别表示整数的和与积，如果两者都为0，则输入结束。
只需要对于每个n和m，输出“Yes”或者“No”，明确有还是没有这种整数就行了。
9 15
5 4
1 -56
0 0

----------
No
Yes
Yes


转化成一个一元二次方程，只要存在根，且为整数，即可满足题意。
/******************
x + y = n
x * Y = m
/******************
两式子联立可得：x*x - n*x + m = 0

（即一个一元二次方程，当根x是整数是，即可满足题意，x是整数，y当然也成了整数）
1.先判断方程的根个数，令d = n*n -4*m   
	若d < 0 ,无解，直接输出No
	若d >=0 ,有解，进而判断他的根是不是整数
2.用求根公式得出根。根 x1 = （ n + sqrt(d) )/ 2;  x2 = （ n - sqrt(d) )/ 2;
	判断x1,x2是不是整数。
**/
int main()
{
	int n,m,i;
	double d,x,y;
	while(scanf("%d%d",&n,&m)&& n||m)
	{
		d=(double)(n*n-4*m);	//判断方程的根个数，令d = n*n -4*m
		if(d<0)	
			printf("No\n");
		else if(d==0)
		{
			if(n%2==0)	 		//根x = n / 2 ；只需要判断n的奇偶性，即可知道根是不是整数
				printf("Yes\n");
			else
				printf("No\n");
		}
			else
			{	//求根公式得出根,判断x1，x2是不是整数
				x=(n+sqrt(d))/2;
				y=(n-sqrt(d))/2;
				if(x-(int)x==0&&y-(int)y==0)
					printf("Yes\n");
				else
					printf("No\n");
			}
	}
	return 0;
}