#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
***************************************************

“回文串”是一个正读和反读都一样的字符串，
请写一个程序判断读入的字符串是否是“回文”。
输入包含多个测试实例，输入数据的第一行是一个正整数n,
表示测试实例的个数，后面紧跟着是n个字符串。
如果一个字符串是回文串，则输出"yes",否则输出"no".

***************************************************
*/
int main()
{
	int N;
	char str[100];
	while(scanf("%d%*c",&N) != EOF)
	{
		for (int i = 0; i < N; i++)
		{
			gets(str);
			int flag;
			int len = strlen(str);
			
			for(int j=0;j<(len/2 - 1);j++)
			{
				if(str[i] == str[len -1-i])
					flag = 1;
				else flag = 0;
			}
			
			
			if(flag)		printf("yes\n");
			else			printf("no\n");
		}
		
	}
	return 0;
}