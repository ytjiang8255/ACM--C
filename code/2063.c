#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
***************************************************

输入数据的第一行是三个整数K , M , N，分别表示可能的组合数目，女生的人数，男生的人数。0<K<=1000
1<=N 和M<=500.接下来的K行，每行有两个数，分别表示女生Ai愿意和男生Bj做partner。最后一个0结束输入。
输出一个整数，表示可以坐上过山车的最多组合数。

6 3 3
1 1
1 2
1 3
2 1
2 3
3 1
0
-------
3

***************************************************
*/
int Find(int x);
int main()
{
	int i,j,k,,n,m,x,y,sum;
	int line[510][510],boy[510],used[510];
	while(scanf("%d%d%d",&k,&n,&m) && k)
	{
		memset(line,0,sizeof(line));
		memset(boy,0,sizeof(boy));
		memset(used,0,sizeof(used));
		for(i=0;i<k;i++)
		{
			scanf("%d%d",&x,&y);
			line[x][y]=1;		//表示 x希望与 y有关系 
		}
		sum=0;
		for(i=1;i<=n;i++)
		{
			memset(used,0,sizeof(used));	//每次都要清 0  
			if(Find(i))			//找到一对就记录 
				sum++;
		}
		printf("%d\n",sum);
	}
	return 0;
}

int Find(int x)
{
	int i,j;
	for(i=1;i<=m;i++)		//遍历所有被选者
	{
		if(line[x][i]==1 && used[i]==0)
		{
			//如果 x对i有好感且在这一个递归选取阶段没有被选取（哪怕是暂时选取，新的递归可能会换）   
			used[i]=1;		//标记被选取
			
			if(boy[i]==0 ||Find(boy[i]))//如果被选者没有归属或他的归属着可以调换（他的归属者可以选择其它被选者） 
			{
				boy[i]=x;			//将归属定为 x  
				return 1;
			}
		}
	}
	return 0;	
}