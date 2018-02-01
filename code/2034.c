#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
***************************************************
切记每次进循环都需要数组清零！！！
切记每次进循环都需要数组清零！！！
切记每次进循环都需要数组清零！！！
***************************************************


每组输入数据占1行,每行数据的开始是2个整数n(0<=n<=100)和m(0<=m<=100),
分别表示集合A和集合B的元素个数，然后紧跟着n+m个元素，
前面n个元素属于集合A，其余的属于集合B. 
每个元素为不超出int范围的整数,元素之间有一个空格隔开.
如果n=0并且m=0表示输入的结束，不做处理。

针对每组数据输出一行数据,表示A-B的结果,如果结果为空集合，则输出“NULL”,
否则从小到大输出结果,为了简化问题，每个元素后面跟一个空格.

***************************************************
*/
int main()
{
	int n, m;
	int a[105], b[105], count[105], flag[105];	//flag数组一定要初始化为0
	while (scanf("%d%d", &n, &m) != EOF)
	{
		int t = 0, temp;

		if (n == 0 && m == 0)	break;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(flag, 0, sizeof(flag));	//切记每次进循环都需要数组清零！！！

		for (int i = 0; i<n; i++)	scanf("%d", &a[i]);
		for (int i = 0; i<m; i++)	scanf("%d", &b[i]);

		for (int i = 0; i<n; i++)
		for (int j = 0; j<m; j++)
		if (a[i] == b[j])
			flag[i] = 1;			//两个for循环后将两个数组相同的元素标记下下标位置信息
		for (int i = 0; i<n; i++)
		if (flag[i] == 0)
		{
			count[t++] = a[i];		//记下没有重复的元素信息，并且利用count数组存放起来
		}

		for (int i = 0; i<t; i++)	//从小到大排列没有重复的元素
		for (int j = i; j<t; j++)
		if (count[i]>count[j])
		{
			temp = count[i];
			count[i] = count[j];
			count[j] = temp;
		}
		if (t == 0)					//空集输出NULL
			printf("NULL");
		else
		for (int i = 0; i<t; i++)//按从小到大的顺寻输出
		{
			printf("%d ", count[i]);	//每个元素后面跟一个空格!!!
//			if (i<t - 1)
//				printf(" ");
		}
		printf("\n");
	}
	return 0;
}