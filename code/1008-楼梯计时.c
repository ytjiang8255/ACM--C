#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
***************************************************

请求列表中的n是正数。这些数字表示在该楼层的电梯会停止，
在指定的顺序。需要花费6秒来移动电梯楼到上一层，花4秒移动到下一层。电梯会在每个停留5秒钟停止。
对于给定的请求列表，你所花费的总时间来计算以满足该请求的列表。
电梯在楼层处的第0开始，并且不需要回到地面的请求。


每种情况下包含一个正整数n，n的正数。所有号码的输入是小于100。
测试情况的n＝0表示的输入端。这个测试案例是不被处理。
总打印时间的一行上的每个测试案例。

***************************************************
*/
int main()
{
	int N, a[101] = { 0 }, Total_time[101] = { 0 };
	while (scanf("%d", &N) != EOF && N !=0 && N>0)
	{

			a[0] = 0;
			Total_time[0] = 0;
			for (int i = 1; i <= N; i++)
			{
				scanf("%d", &a[i]);

				if (a[i]>a[i - 1])
					Total_time[i] = (a[i] - a[i - 1]) * 6 + 5;
				else
					Total_time[i] = (a[i - 1] - a[i]) * 4 + 5;

				Total_time[0] += Total_time[i];
//				printf("%d\n", Total_time);
			}
			printf("%d\n", Total_time[0]);
		
	}	
	return 0;
}