#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
设计迷宫的思路不一样，首先她认为所有的通道都应该是双向连通的，就是说如果有一个通道连通了房间A和B，
那么既可以通过它从房间A走到房间B，也可以通过它从房间B走到房间A，为了提高难度，
小希希望任意两个房间有且仅有一条路径可以相通（除非走了回头路）。



输入包含多组数据，每组数据是一个以0 0结尾的整数对列表，表示了一条通道连接的两个房间的编号。
房间的编号至少为1，且不超过100000。每两组数据之间有一个空行。 
整个文件以两个-1结尾。

对于输入的每一组数据，输出仅包括一行。如果该迷宫符合小希的思路，那么输出"Yes"，否则输出"No"。
**/

int set[100010];
bool mark[100010];
int findx(int x);
bool merge(int x, int y);


int main()
{
	int a, b, i, flag, cnt;
	int min, max;
	while (scanf("%d%d", &a, &b) && (a != -1 && b != -1))
	{

		flag = 1; 
		cnt = 0;
		if (a == 0 && b == 0)
		{
			printf("Yes\n");	//如果每测试数据已0  0输入，也应打印出Yes！
			continue;
		}

		for (i = 0; i<100010; i++)
		{
			set[i] = i;
			mark[i] = 0;	//设一个mark[i]来标记数字是否出现过
		}
		min = 9999999; 
		max = -1;
		while (a || b)		//即a，b不全为 0
		{
			if (a>max) max = a;
			if (b>max) max = b;
			if (a<min) min = a;
			if (b<min) min = b;
			
			//mark[i]=1 是记录数字已经出现过了
			mark[a] = 1;
			mark[b] = 1;
			if (merge(a, b) == false)	//findx(a) == findx(b)即a，b有共同的根结点，彼此相通则flag置零
				flag = 0;
			scanf("%d%d", &a, &b);
		}

		if (flag == 0)
			printf("No\n");
		else
		{
			/*
			如果两个数字能查找到相同的根结点就证明二者已经是相通的，
			再输入二者的关系就变成有多条相通的路径了。
			这时候答案肯定要输出“No”，如果两个数字不能查找到共同的根结点把两数字所在的集合合并，
			直到一组数据输入结束后，再进行判断，是否输入的关系每个数字之间都有相通的路径
			*/
			for (i = min; i <= max; i++)
			if (mark[i] && set[i] == i)
				cnt++;	//这里有一点需要注意，这里也是很多人卡壳的地方！  
						//题目给出的并不一定是只有一个集合，它可能给出多个集合，彼此并不联通  
						//而这种情况按照上面的方式判断不出来，因此我们最后还要判断集合的个数  
			if (cnt == 1)
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}


int findx(int x)
{
	int r = x;
	while (set[r] != r)
		r = set[r];
	return r;
}


//每次输入一对数字的关系则进行查找根结点的函数,并通过合并函数来判断两个数是否已经联通
bool merge(int x, int y)
{
	int fx, fy;
	fx = findx(x);
	fy = findx(y);
	if (fx != fy)
	{
		set[fx] = fy;
		return true;
	}
	else
		return false;
}