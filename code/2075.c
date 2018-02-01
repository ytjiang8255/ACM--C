#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
输入数据的第一行是一个数据T，表示有T组数据。
每组数据有两个正整数A和B(A,B<10^9)。
输出"YES"表示可以被整除，"NO"表示不能被整除。
**/

long long A,B;
int main()
{
	int T;
	while(scanf("%d",&T)==1)
	{
		while(T--) 
		{
			scanf("%lld%lld",&A,&B);
		//	printf(a % b == 0 ? "YES\n" : "NO\n"); 
			if(A%B)
				printf("NO\n");
			else
				printf("YES\n");	
		}
	}
	return 0;
}