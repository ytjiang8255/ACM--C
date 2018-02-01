#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
拆开一看是一个棋盘，从起点(0，0)走到终点(n,n)的最短路径数是C(2n,n)
现在小兔又想如果不穿越对角线(但可接触对角线上的格点)，这样的路径数有多少?

输入：	一个数n(1<=n<=35)，当n等于－1时结束输入
输出：	路径数，具体格式看Sample
1
3
12
-1
------
1 1 2
2 3 10
3 12 416024

卡塔兰数递推关系的解为：h(n)=c(2n,n)/(n+1)=(2n)!/(n!*(n+1)!)  (n=1,2,3,...)
令h(0)=1,h(1)=1，catalan数满足递推式 ：h(n)= h(0)*h(n-1)+h(1)*h(n-2) + ... + h(n-1)*h(0) (n>=2)
本题的一个巧妙的地方是：路径是关于对角线对称的，所以须将卡塔兰数乘以2
**/
#define Max 36

int main()
{
	int n,m=1;			//n为所要求的数据值 m则为第几次输入次数
	long long a[Max]={0};
	a[0]=1;
	a[1]=1;
	for(int i=2;i<Max;i++)
	for(int j=0;j<=i-1;j++)	//不跨越对角线，因此j<=i-1
		a[i]+=a[j]*a[i-1-j];//相乘的两个数的下标和为 i-1
	
	while(scanf("%d",&n)==1 && n!=-1)
		printf("%d %d %lld\n",m++,n,2*a[n]);
			//	棋盘是对角线对称的所以求出一侧乘以2得出最后结果
	
	return 0;
}