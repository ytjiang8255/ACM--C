#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
***************************************************

输入包含一堆鼠的数据，每行一只鼠，以文件结尾终止。
特定鼠的数据将由一对整数组成：第一个表示其大小（克），第二个表示其速度（以厘米每秒为单位）。 
两个整数都在1到10000之间。每个测试用例中的数据将包含最多1000只老鼠的信息。

两只老鼠可能具有相同的重量，相同的速度，甚至相同的重量和速度。
程序应输出一系列数据; 第一行应包含数字n; 其余的n行应每个都包含一个正整数（每个代表一个鼠标）。 
如果这些n个整数是m [1]，m [2]，...，m [n]，则必须是这样

W [m [1]] <W [m [2]] <... <W [m [n]] 和 S [m [1]]> S [m [2]]> ...> S [m [n]]

为了使答案正确，n应尽可能大。
所有不平等都是严格的：权重必须严格增加，速度必须严格降低。 给定输入可能有很多正确的输出，您的程序只需要找到一个。

6008 1300
6000 2100
500 2000
1000 4000
1100 3000
6000 2000
8000 1400
6000 1200
2000 1900
>>>	4
	4
	5
	9
	7
***************************************************
*/
struct data
{
	int weight;
	int speed;
	int num;

}mice[1010];

int cmp(const void* a, const void* b)
{
	if ((*(struct data*)a).weight != (*(struct data*)b).weight)
		return (*(struct data*)a).weight - (*(struct data*)b).weight;
	else
		return (*(struct data*)a).speed - (*(struct data*)b).speed;
}

int len[1010], route[1010], ans[1010];


int main()
{
	int k = 1, i, j, max_len = 0, end;
	//题目中给了最多1000只老鼠但是没说给几组测试数据所以尽量开大点，这里输出时是特殊输出：Ctrl+Z  
	while (scanf("%d%d", &mice[k].weight, &mice[k].speed) != EOF)
	{
		mice[k].num = k;	
		k++;
		//mice[k].num = k++;
	}

	qsort(mice + 1, k - 1, sizeof(struct data), cmp);

	for (i = 1; i<k; i++)
	{
		len[i] = 1;
		route[i] = 0;
	}

	for (i = 1; i<k; i++)
	{
		for (j = 1; j<i; j++)
		{
			if (mice[i].weight>mice[j].weight && mice[i].speed<mice[j].speed && len[i]<len[j]+1)
			{
				len[i] = len[j] + 1;
				route[i] = j;
			}
		}
	}

	end = 1;
	max_len = len[1];

	for (i = 2; i<k; i++)
	if (max_len<len[i])
	{
		max_len = len[i];
		end = i;
	}
	printf("%\n", max_len);

	for (i = 1; i<k; i++)
	{
		ans[i] = end;
		end = route[end];
	}

	for (i = max_len; i >= 1; i--)
		printf("%d\n", mice[ans[i]].num);
	return 0;
}