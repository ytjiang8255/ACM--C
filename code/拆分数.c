// Author by lwg
//#include <iostream>
//using namespace std;
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

const int lmax=10000;
int c1[lmax+1],c2[lmax+1];
int main()
{
	int n,i,j,k;
	while(scanf("%d",&n) && n!=0)
//	while (cin>>n)	
	{
		for (i=0;i<=n;i++)
		{
			c1[i]=1;	
			c2[i]=0;	
		}
		
		for (i=2;i<=n;i++)		
		{	for (j=0;j<=n;j++)				
			for (k=0;k+j<=n;k+=i)				 
			{  
				c2[j+k]+=c1[j];  
			}
			printf("c2[%d]=%d\tc1[%d]=%d\n", i, c2[i], i, c1[i]); //测试语句

			
			for (j=0;j<=n;j++)		
			{ 
				c1[j]=c2[j];	
				c2[j]=0;  
			}	
		}	
		printf("%d\n",c1[n]);
	//	cout<<c1[n]<<endl;
	}	
	return 0;
}
