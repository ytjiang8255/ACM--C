#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
“给定一些中国硬币（硬币）（三种 - 1，2，5），它们的数字分别为num_1，num_2和num_5，
		请输出您不能用给定硬币支付的最小值。
输入:	包含多个测试用例。 每个测试用例包含3个正整数num_1，num_2和num_5（0 <= num_i <= 1000）。 
		包含0 0 0的测试用例终止输入，并且不对该测试用例进行处理。	
输出:	给定硬币不能支付的最小正值，一条线一条

**/
const int lmax=10000;
int c1[lmax+1],c2[lmax+1];
/*
ACM编译出现的错误！
应输入常量表达式
不能分配常量大小为 0 的数组
*/
int main()
{
	int num_1,num_2,num_5;
//	const int lmax=10000;
//	int c1[lmax+1]={0},c2[lmax+1]={0};   //数组初始化清零
	while(scanf("%d%d%d",&num_1,&num_2,&num_5) != EOF &&(num_1||num_2||num_5)!=0)
						//   切记分号 ; 不然进不去循环程序！！！
	{
		int Max=num_1+num_2*2+num_5*5;
		
		for(int i=0;i<=num_1;i++)
			c1[i]=1;
		//第一括号内的数和第二个括号的相乘
		for(int i=0;i<=num_1;i++)
			for(int j=0;j<=num_2*2;j+=2)	//num_2*2代表的是数的幂
				c2[k+j]+=c1[j];				
		//合并同类项，如：(4*x^3) *(2*x^3)  = 6*x^3     即：c1[3] = 4   ,c2[3]=2  ,则相乘的话，等于c2[3] = 6  
		
		 //把暂时的系数值存在要输出的c1数组上
		for(int i=0;i<=num_1+num_2*2;i++)
		{
			c1[i]=c2[i];
			c2[i]=0;
		}
		
		for(int i=0;i<=num_1+num_2*2;i++)		 //此时x的幂最大是num_1+num_2*2   
			for(int j=0;j<=num_5*5;j+=5)
				{
					c2[i + j] += c1[j];
		//			printf("1.c2[%d] = %d\n", i+j, c2[i+j]);
				}

		for(int i=0;i<=num_1+num_2*2+num_5*5;i++)
		{
			c1[i]=c2[i];
			c2[i]=0;
		//	printf("2.c1[%d] = %d\n",i, c1[i]);
		}	
		
		int i=0;
		for (int i = 0; i <= Max; i++)
		{
			if (c1[i] == 0)			//为0，表示不能组合出来的项，输出
			{
				printf("%d\n", i);
				break;				//控制程序跳出当前循环，继续执行下一段的程序代码
			}
			if (i ==Max)
			{
				printf("%d\n", i);
			}
		}
		
	}
	return 0;
}