include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
***************************************************

统计每个元音字母在字符串中出现的次数。
输入数据首先包括一个整数n，表示测试实例的个数，
然后是n行长度不超过100的字符串。

***************************************************
*/
int main()
{
	char str[100];
	int N;
	while (scanf("%d%*c", &N) != EOF)
	{
		
		for (int i = 0; i < N; i++)
		{
			int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0;
		//	scanf("%s", str);
			gets(str);

			int len = strlen(str);
			for (int i = 0; i<len; i++)
			{
				if (str[i] == 'a')		num1 += 1;
				if (str[i] == 'e')		num2 += 1;
				if (str[i] == 'i')		num3 += 1;
				if (str[i] == 'o')		num4 += 1;
				if (str[i] == 'u')		num5 += 1;
			}
			printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n", num1, num2, num3, num4, num5);
			if (i<N - 1)		printf("\n");
		}

//		for (int i = 0; i<N; i++)
//		{
//			printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n", num1, num2, num3, num4, num5);
//			if (i<N - 1)
//				printf("\n");
//		}
			
	}
	
	return 0;
}