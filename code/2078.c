#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
在复习完一门课后，他总是挑一门更简单的课进行复习，而他复习这门课的效率为两门课的难度差的平方,
而复习第一门课的效率为100和这门课的难度差的平方
输入数据的第一行是一个数据T，表示有T组数据。
每组数据的第一行是两个整数总科目n(1 <= n <= 40)，复习科目m(1 <= m <= n)。
接着有n行，每行有一个正整数a(1 <= a <= 100)，表示这门课的难度值。
输出一个整数，表示最高效率值。!!!就是100和最小难度的差的平方了吗。m没什么卵用
2
2 2
52
25 
--------
5625
**/
int main()
{
	int T,n,m,i,j;
	double sum,s[41],Min;
	while(scanf("%d",&T)==1)
	{
		while(T--)
		{
			sum=0;
			scanf("%d%d",&n,&m);
/*			
			Min=100;
			for(i=0;i<n;i++)
			{
				
				scanf("%lf",&s[i]);
				if(Min>s[i])
					Min=s[i];
			}
*/				
			for(i=0;i<n;i++)
				scanf("%lf",&s[i]);
			Min = s[0];
			for (i = 1; i < n; i++)
			{
				if (Min>s[i])
					Min = s[i];
			}
			sum = (100 - Min)*(100 - Min);
			printf("%.0lf\n",sum);
		}	
	}	
	return 0;
}