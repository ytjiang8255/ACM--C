#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
***************************************************
 f(A) = 1, f(a) = -1, f(B) = 2, f(b) = -2, ... f(Z) = 26, f(z) = -26;
给一个字母X和Y，要输出的结果F(x)+y。

***************************************************
*/
int main()
{	int n, y;
	char c;
	while (scanf("%d", &n) != EOF)
	{
//		for (int i = 0; i < n; i++)
		while(n--)
		{
			scanf("%c%d", &c, &y);
			if (c >= 'A' && c <= 'Z')
			{
				printf("%d\n", y + (int)(c - 'A' + 1));
			}

			if (c >= 'a' && c <= 'z')
			{
				printf("%d\n", y - (int)(c - 'a' + 1));
			}

		}
	}
	
	return 0;
}