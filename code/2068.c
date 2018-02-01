#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
错排公式：f(i) = (i - 1) * [f(i-1) + f(i-2)]
============================================
输入的数据里有多个case,每个case包括一个n（排序），代表有几个女生，（n<=25）, n = 0输入结束。
1
2
0
------
1
1


**/
#define Max 26

int main()
{
	int n,i;
	long long fac[Max]={1,1,2},s[Max]={0,0,1},sum;
	for(i=3;i<Max;i++)
	{
		s[i]=(i-1)*(s[i-1]+s[i-2]);
		fac[i]=i*fac[i-1];
	}
	
	while(scanf("%d",&n)==1 && n)
	{
		sum=0;			//每次输入n之后将先前的sum值清零
		if(n==1 || n==2 ||n==3)
		{
			printf("1\n");
			continue;
		}
		for(int k=n/2;k>1;k--)
			sum +=s[k]*fac[n]/(fac[k]*fac[n-k]);
		printf("%lld\n",sum);
	}	
	return 0;
}