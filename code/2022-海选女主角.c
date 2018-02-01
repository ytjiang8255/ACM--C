#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
****************************************

输入数据有多组，每组的第一行是两个整数m和n，
表示应聘MM的总共的行列数，
然后是m行整数，每行有n个，m和n的定义见题目的描述。
对于每组输入数据，输出三个整数x,y和s，
分别表示选中的MM的行号、列号和分数。
note:行号和列号从一开始，如果有多个MM的分数绝对值一样，
那么输出排在最前面的一个
（即行号最小的那个，如果行号相同则取列号最小的那个）。 
2 3
1 4 -3
-7 3 0
-----------
2 1 -7

fabs()是对浮点数取绝对值，abs()是对整数取绝对值。
****************************************
*/
int main()
{
	int n, m, i, j, x, y, s;
	double d, Max;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		Max = 0;
		x = 0;
		y = 0;
		for (i = 0; i<n; i++)
		for (j = 0; j<m; j++)
		{
			scanf("%lf", &d);
			if (fabs(d)>fabs(Max))
			{
				x = i;
				y = j;
				Max = d;
			}
		}
		printf("%d %d %.0lf\n", x + 1, y + 1, Max);		//数组下标从0开始的
	}
	return 0;
}