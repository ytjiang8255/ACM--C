#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
 5 types of coins: 50-cent, 25-cent, 10-cent, 5-cent, and 1-cent
输入:	包含任意数量的行数，每一行由一个数字（≤250）组成，金额为分。
输出:	包含使用上述5种类型的硬币进行变换的不同方式的数量。

**/



int main()
{
	int i,j,k,N,l,m,sum;
	while(scanf("%d",&N)==1)
	{
		if(N==0)
		{
			printf("1\n");
			continue;
		}
		sum=0;
		for(i=0;i<=N;i++)
			for(j=0;j*5<=N-i;j++)
				for(k=0;k*10<=N-i-5*j;k++)
					for(l=0;l*25<=N-i-5*j-10*k;l++)
					{
						m=N-i-5*j-10*k-l*25;
						if(i+j+k+l+m/50<=100 && m%50==0)
					//	if(i+j+k+l<=100 && m==0)		//也是可以的，只需m最后是0就进入sum++
							sum++;
					}
		printf("%d\n",sum);
	}
	
	return 0;
}