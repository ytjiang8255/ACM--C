#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
一个整数，只知道前几位，不知道末二位，被另一个整数除尽了，那么该数的末二位该是什么呢？
输入数据有若干组，每组数据包含二个整数a，b（0<a<10000, 10<b<100），若遇到0 0则处理结束。
对应每组数据，将满足条件的所有尾数在一行内输出，格式见样本输出。同组数据的输出，其每个尾数之间空一格，行末没有空格。
200 40
1992 95
0 0
----------
00 40 80
15
**/
int main()
{
	int i,a,b,num[100]={0},sum;
	while(scanf("%d%d",&a,&b)!=EOF &&(a || b))
	{
		sum=0;
		for(i=0;i<=99;i++)
		{
			if((i+a*100)%b==0)	//补全a的后两位数，在利用循环遍历查找能够整除的数
			{
				num[sum]=i;		//利用sum来作为数组下标，方便存放所寻找到的数
				sum++;
			}
		}
		
		for(i=0;i<sum-1;i++)
		{
			if(num[i]<10)
				printf("0");
			printf("%d ",num[i]);	
		}
		if(num[sum-1]<10)
			printf("0");
		printf("%d\n",num[sum-1]);
	}
	return 0;
}