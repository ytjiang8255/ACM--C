#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
球赛的规则如下：
如果A打败了B，B又打败了C，而A与C之间没有进行过比赛，那么就认定，A一定能打败C。
如果A打败了B，B又打败了C，而且，C又打败了A，那么A、B、C三者都不可能成为冠军。
根据这个规则，无需循环较量，或许就能确定冠军。

输入   含有一些选手群，每群选手都以一个整数n(n<1000)开头，后跟n对选手的比赛结果，
       比赛结果以一对选手名字（中间隔一空格）表示，前者战胜后者。如果n为0，则表示输入结束。
输出   对于每个选手群，若你判断出产生了冠军，则在一行中输出“Yes”，否则在一行中输出“No”。
3
Alice Bob
Smith John
Alice Smith
5
a c
c d
d e
b e
a d
0
---------------
Yes
No

strcmp函数是比较两个字符串的大小,返回比较的结果。一般形式是：  i=strcmp(字符串，字符串);
①字符串1'小于'字符串2,strcmp函数返回	负值;
②字符串1'等于'字符串2,strcmp函数返回	零;
③字符串1'大于'字符串2,strcmp函数返回	正值;
**/
int main()
{
	int n,i,j,visit[1001],sum;
	char win[1001],lose[1001];
	while(scanf("%d",&n)==1 && n)
	{
		sum=0;
		memset(visit,0,sizeof(visit));		//必须用memset函数将数组清零！！！
		for(i=0;i<n;i++)
		{
			scanf("%s%s",&win[i],&lose[i]);
			visit[i]=1;
		}
		
		for(i=0;i<n;i++)	
		{
			for(j=0;j<n;j++)
			{
				if(strcmp(win[i],lose[j])==0)		//若某冠军在接下来比赛中输了则visit[i]赋值为0
					visit[i]=0;
				if(i!=j &&strcmp(win[i],win[j])==0)	//若某冠军在接下来比赛中还是赢了则visit[j]赋值为0
					visit[j]=0;
			}
			sum+=visit[i];		//将标记的冠军数累加
		}
		if(sum==1)				//冠军只有一个，因此只要sum==1才输出Yes
			printf("Yes\n");
		else
			printf("No\n");
		
	}
	return 0;
}