#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**

**/

int main()
{
	int N,m,i;
	float a[101]={0},Max,temp;
	while(scanf("%d",&N)==1)
	while(N--)
	{
		scanf("%d",&m);
		for(i=0;i<m;i++)
			scanf("%f",&a[i]);
		Max=a[0];
		for(i=1;i<m;i++)
		{
			if(a[i]>Max)
			{
				temp=a[i];
				a[i]=Max;
				Max=temp;
			}
		}
		printf("%.2f\n",Max);
		
	}	
	return 0;
}