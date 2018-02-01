#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
输入首先是一个正整数M，表示M个测试实例。每个实例的输入有2行，
首先是一个正整数N（N <= 500)，表示有N个朋友，下一行是N个正整数，表示具体的坐标(所有数据均<=10000).
输出访问完所有朋友所花的最少时间，每个实例的输出占一行。

a[i-1][j-1] = a[i][j]+a[i-1][j-1];
a[i-1][j-1] = a[i][j-1]+a[i-1][j-1];
**/
int main()
{
	int T,n,i,j,a[120][120],dp[120][120],x,y,Max;
	while(scanf("%d",&T)==1)
		while(T--)
		{
			scanf("%d",&n);
			for(i=1;i<=n;i++)
				for(j=1;j<=i;j++)
				scanf("%d",&a[i][j]);
			for(j=1;j<=n;j++)
				dp[n][j]=a[n][j];
			for(i=n-1;i>=1;i--)
				for(j=1;j<=i;j++)
				{
					x=dp[i+1][j];
					y=dp[i+1][j+1];
					Max=x>y?x:y;
					dp[i][j]=a[i][j]+Max;
					
				}
			printf("%d\n",dp[1][1]);
		}
	return 0;
}

-------------------------------------------
#include <iostream>  
using namespace std;    
int a[110][110];  
int d[110][110];  
int dd(int i,int j,int n){  
if(d[i][j]>=0) return d[i][j];  
return d[i][j]=a[i][j]+(i==n?0:max(dd(i+1,j,n),dd(i+1,j+1,n)));  
}  
int main()  
{  
int C;  
cin>>C;  
while(C--){  
int N;  
cin>>N;  
memset(d,-1,sizeof(d));  
for(int i=1;i<=N;i++)  
for(int j=1;j<=i;j++)  
cin>>a[i][j];  
cout<<dd(1,1,N)<<endl;  
}  
return 0;  
}  
