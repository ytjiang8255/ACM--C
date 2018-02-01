#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
约19世纪末，在欧州的商店中出售一种智力玩具，在一块铜板上有三根杆，最左边的杆上自上而下、由小到大顺序串着由64个圆盘构成的塔。
目的是将最左边杆上的盘全部移到右边的杆上，条件是一次只能移动一个盘，且不允许大盘放在小盘的上面。
现在我们改变游戏的玩法，不允许直接从最左(右)边移到最右(左)边(每次移动一定是移到中间杆或从中间移出)，也不允许大盘放到下盘的上面。

包含多组数据，每次输入一个N值(1<=N=35)。
输出移动最小的次数

1
3
12
------
2
26
531440

分析：
假设将n层塔从A经B挪到C需要f[n]步。那么具体的移动过程可以这样看：
将上面n-1层从A经B挪到C需要f[n-1]步，再将第n层从A挪到B，
需要一步，再将上n-1层从C经B挪到A，需要f[n-1]步，再将第n层从B挪到C，
需要一步，再将上n-1层从A经B挪到C，需要f[n-1]步，总计3*f[n-1] + 2步，其中 f[1] = 2;
**/

int main()
{
	long long dp[36]={0,2};
	int  n;
	for(i=2;i<36;i++)
		dp[i]=dp[i-1]*3+2;
	while(scanf("%d",&n)==1)
		printf("%lld\n",dp[n]);
	return 0;
}
=================================================
long long  min(long long x,long long y);
int main()
{
	long long dp[66];
	int i,n,x;
	memset(dp,0,sizeof(dp));
	dp[1]=1;
	dp[2]=3;
	for(i=3;i<=64;i++)
	{
		for(j=1;j<i;i++)
			dp[i]=Min(dp[i],2*dp[j]+pow(2,i-j)-1);
	}
	
	while(scanf("%d",&n)==1)
		printf("%lld\n",dp[n]);
		
	return 0;
}

long long  min(long long x,long long y)
{
	return(x<y?x:y)
	
}