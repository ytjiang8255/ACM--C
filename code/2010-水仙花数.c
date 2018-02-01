#include <stdio.h>
#include <math.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/*
	*************************************************************
	“水仙花数”是指一个三位数，它的各位数字的立方和等于其本身
	比如：153=1^3+5^3+3^3。现在要求输出所有在m和n范围内的水仙花数。
	************************************************************

*/
int main(void)
{
	int M,N,t,h,g,i;
	while (scanf("%d%d",&M,&N) != EOF)
/*	{
		for(i=M;i<=N;i++)
		{
			t =i%100;
			h =i%100/10;
			g =i%100%10/1；
			if(i == t*t*t+h*h*h+g*g*g)
				printf("%d",i);
		}
		
	}
*/	

	{
		if (M <= N && M >= 100 && N <=1000)
		{
			int d = 0;
			for (i = M; i <= N; i++)
			{
				t = i / 100;		//求百位的数字
				h = i % 100 / 10;	//求十位的数字
				g = i % 10;			//求个位的数字
				if (i == (t*t*t + h*h*h + g*g*g))
				{
					if (d != 0)
						printf(" ");
					printf("%d", i);
					d += 1;
				}
			}
			if (d == 0)
				printf("no\n");
			else printf("\n");
		}
	}
	return 0;

}