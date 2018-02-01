#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
***************************************************

首先是一个整数N，表示测试实例的个数，然后是N行数据，
每行有6个整数AH,AM,AS,BH,BM,BS，
分别表示时间A和B所对应的时分秒。题目保证所有的数据合法。
对于每个测试实例，输出A+B，每个输出结果也是由时分秒3部分组成，
同时也要满足时间的规则（即：分和秒的取值范围在0~59），
每个输出占一行，并且所有的部分都可以用32位整数表示。

***************************************************
*/
int main()
{
	int N,time[10]；
	while(scanf("%d",&N) != EOF)
	{
		for(int i=0;i<N;i++)
			for(int j=0;j<6;j++)
			{
				scanf("%d",&time[i]);
			}
		int hour =time[0] + time[3];
		int minute =time[1] + time[4];
		int second =time[2] + time[5];
		
		if(second>60)	{second -=60; minute +=1;}
		
		if(minute>60)	{minute -=60; hour +=1;}
		
		for(int i=0;i<N;i++)
			printf("%d %d %d\n",hour,minute,second);
	}
	
	return 0;
}