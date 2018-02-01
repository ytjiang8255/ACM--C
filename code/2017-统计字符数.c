#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
****************************************

对于给定的一个字符串，
统计其中数字字符出现的次数。

****************************************
*/

int main(void)
{
	int N=0, lenth;
	char str[100];
	while (scanf("%d", &N) != EOF)
	{
		for (int i = 0; i<N; i++)
		{
	//		scanf("%s", &str[i]); 
			scanf("%s", str);		//输入字符串，一个字符一个数组格子里
			lenth = 0;
			int str_len = strlen(str);//获取字符串的长度，便于条件判断
			for (int j = 0; j < str_len; j++)
			{	//
				if (str[j] >= '0' && str[j] <= '9')
				lenth += 1;
			}
			printf("%d\n", lenth);
		}
		
	}
	return 0;
}