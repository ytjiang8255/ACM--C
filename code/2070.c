#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**


**/

int main()
{
	int n,i;
	long long f[51];
//	long long f[n];		//切记定义数组需要明确数组的长度范围！！！
	while(scanf("%d",&n)==1 && n!=-1)
	{
		f[0]=0;
		f[1]=1;
		for(i=2;i<=n;i++)
		{
			f[i]=f[i-1]+f[i-2];
			
		}
		printf("%lld\n",f[n]);
	}
	
	return 0;
}

