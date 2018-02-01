#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
***************************************************
给你一个数字(十进制），应该输出（它的N进制）（0 <n <1000）

***************************************************
*/
int main()
{
	int n,scale,a[200],i,j;
	while(scanf("%d%d",&n,&scale) != EOF)	//n为输入的整数，scale为转换进制
	{
//		if(n>0 && n<1000)
		{
				i=0;
				j=0;
				while(n)
				{
					a[i]=n % scale;
					n /= scale;
					i++;
				}
				
				for(j=i-1;j>=0;j--)
					printf("%d",a[j]);
				printf("\n");		
		}	
	}
	return 0;
}