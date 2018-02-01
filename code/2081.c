#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
输入数据的第一行是一个N(N <= 200)，表示有N个数据，接下来的N行每一行为一个11位的手机号码。
输出应包括N行，每行包括一个对应的短号(6+手机号的后5位)，输出应与输入的顺序一致。
**/
int main()
{
	char num[12],t;
	int N,i;
	while(scanf("%d",&N)==1)
	{
		while(N--)
		{
		for(i=0;i<=11;i++)
		{
			t=getchar();
			if(t>='0'&&t<='9')		//切记加 = 
				num[i]=t;
		}
		printf("6");
		for(i=7;i<=11;i++)			//利用打印的规则输出'6'+字符串的后5位
			{
				printf("%c",num[i]);
			}	
			printf("\n");
		}
	}
	return 0;
}