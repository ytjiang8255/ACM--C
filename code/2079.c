#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/*
输入数据的第一行是一个数据T，表示有T组数据。
每组数据的第一行是两个整数n(1 <= n <= 40)，k(1 <= k <= 8)。
接着有k行，每行有两个整数a(1 <= a <= 8),b(1 <= b <= 10)，表示学分为a的课有b门。
输出一个整数，表示学n个学分的组合数。
*/

int main()
{
	int T,a_score[9],a_kinds[9],a_all,a_num,i,j,k,t;
	int c1[1000],c2[1000];
	while(scanf("%d",&T)==1)
	{
		while(T--)
		{
			scanf("%d%d",&a_all,&a_num);
			for(i=0;i<a_num;i++)
				scanf("%d%d",&a_score[i],&a_kinds[i]);
				
			for(i=0,j=0;i<=a_all&&j<=a_kinds[0];i+=a_score[0],j++)
				c1[i]=1;
			for(i=0;i<=a_all;i++)
				c2[i]=0;
			
			for(i=1;i<=a_num;i++)		//
			{
				for(j=0;j<=a_num;j++)
					for(k=0,t=0;k+j<=a_num&&t<=a_kinds[i];k+=a_score[i],t++)
						c2[j+k]=c1[j]+c2[j+k];
					for(j=0;j<=a_all;j++)
					{
						c1[j]=c2[j];
						c2[j]=0;
					}	
			}
			printf("%d\n",c1[a_all]);
		}	
	}
	return 0;
}