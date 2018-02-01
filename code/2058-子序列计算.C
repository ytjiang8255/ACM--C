#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
***************************************************

输入包含多个测试包含两个整数N、M（1<=N,M<=10),
输入端与N=M=0则退出。
打印所有可能的子序列（sub-sequence），其总和为M.格式显示在下面的示例中。
在每个测试用例之后打印一个空行。

穷举是穷举，还不能任意穷举，要不超时！

设初始值i，个数为j的数列满足要求，则由数列求和公式可知（高斯定理）
（i+i+j-1)*j/2=m	==>  i=(2*M/j +1-j)/2

所以j肯定小于等于sqrt(2*m)，穷举。
***************************************************
*/
int main()
{
	int N,M,i,j;
	while(scanf(%d%d,&N,&M) != EOF)
	{
		if(N==0 && M==0)	break;
		for(j=(int)sqrt((double)(2*M));j>=1;j-- )
		{
			i=(2*M/j +1-j)/2;		//子序列的起始数
			if((2*i +j-1)*j/2==M)
				printf("[%d,%d]\n",i,i+j-1);
			
		}
		printf("\n");
	}
	
	return 0;
}