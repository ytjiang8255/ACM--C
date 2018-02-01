#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
有四种组合的硬币支付十学分：
十个1信用硬币，
一个4信用硬币和6个1信用硬币，
两个4信用硬币和2个1信用硬币，以及
一个9信用硬币和一个1信用硬币。


您的使命是计算使用Silverland硬币支付给定金额的方法的数量。
输入由每行包含一个整数的行组成，后者是包含零的行。 
你可以假定所有的金额都是正数，小于300。
对于给定量的每一个，应该输出一行包含表示硬币组合数的单个整数。 输出中不会出现其他字符。
**/

const int lmax=300;
int c1[lmax+1],c2[lmax+1];
int main()
{
	int n,i,j,k;
	while(scanf("%d",&n) && n!=0)
	//2.0		int elem[17]={1,4,9,16,25,36,49,64,81,100,121,144,169,196,225,256,289};
//	while (cin>>n)	
	{
		for (i=0;i<=n;i++)
		{
			c1[i]=0;	
			c2[i]=0;	
		}
		for (i=0;i<=n;i++) 
			c1[i]=1;
		for (i=2;i<=17;i++)		
		{	for (j=0;j<=n;j++)				
			for (k=0;k+j<=n;k+=i*i)
	//2.0		for (k=0;k+j<=n;k+=elem[i-1])
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
