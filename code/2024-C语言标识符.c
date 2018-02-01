#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
****************************************

输入一个字符串，判断其是否是C的合法标识符。
输入数据包含多个测试实例，数据的第一行是一个整数n,
表示测试实例的个数，然后是n行输入数据，
每行是一个长度不超过50的字符串。
如果输入数据是C的合法标识符，则输出"yes"，否则，输出“no”。
（C 规定，标识符只能是字母(A～Z，a～z)、数字(0～9)、下划线( _ )组成的字符串，
	并且其第一个字符必须是字母或下划线。）
	
****************************************
*/
int main()
{
	int n, i, k, t;
	char s[60];
	while (scanf("%d", &n) != EOF)
	{
		getchar();
		while (n--)
		{
			gets(s);
			t = strlen(s);
			if (t>50)
			{
				printf("no\n");
				continue;
			}
			if (!((s[0] >= 'a'&&s[0] <= 'z') || (s[0] >= 'A'&&s[0] <= 'Z') || s[0] == '_'))
			{
				printf("no\n");
				continue;
			}


			k = 1;
			for (i = 0; s[i] != '\0'; i++)
			{
				if (s[i] == ' ')
				{
					k = 0;
					break;
				}
				if (!((s[i] >= 'a'&&s[i] <= 'z') || (s[i] >= 'A'&&s[i] <= 'Z') || (s[i] >= '0'&&s[i] <= '9') || s[i] == '_'))
				{
					k = 0;
					break;
				}
			}
			if (k == 0)
			{
				printf("no\n");
				continue;
			}
			else
				printf("yes\n");
		}
	}
	return 0;
	
	
/*	int flag1 = 0, flag2 = 0, i, n;
	char str[104];

	while (scanf("%d", &n) != EOF)
	{
		getchar();
		while (n--)
		{
			gets(str);
				flag1 = 0, flag2 = 0;
				if ((str[0] == '_') || (str[0] >= 'a'&& str[0] <= 'z') || (str[0] >= 'A'&& str[0] <= 'Z'))
					flag1 = 1;

				int len = strlen(str);
				if (len > 50)
					flag2 = 0;
				for (i = 1; i < len; i++)
				{
					if (str[i] == ' ')
					{
						flag2 = 0;
						break;
					}
					if ((str[i] == '_') || (str[i] >= 'a'&& str[i] <= 'z') || (str[i] >= 'A'&& str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9'))
						flag2 = 1;
				}
				
				if (flag1 && flag2)
					printf("yes\n");
				else
					printf("no\n");
		}
	}	
	return 0;
*/
}