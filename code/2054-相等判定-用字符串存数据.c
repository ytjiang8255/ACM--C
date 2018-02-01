#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/*
***************************************************

题目上没给具体的数值类型，所以要开一个很大的字符数组。
要注意下面几种情况：
1）前面的无效0去掉
2）小数点后面的无效0去掉
3）-0=0
4）可以去掉的话，最好去掉小数点，防止10==10.0这种情况发生

***************************************************
*/
void change(char str[])
{
	int len = strlen(str);
	int flag = 0, i = 0;

	for (int i = 0; i<len; i++)
	{
		if (str[i] == '0' && str[i+1] !='0')
		{
			flag = 1;
			break;
		}
	}
	if (flag)
	{
		for (int i = 0; i <= len; i++)
		{
			if (str[i] == '0')
				str[i] = '\0';
			else break;
			len--;
		}
		if (str[len + 1] != '0')
			str[len] = '\0';
	}


	for (int i = 0; i<len; i++)
	{
		if (str[i] == '.')
		{
			flag = 1;
			break;
		}
	}
	if (flag)
	{
		for (int i = len - 1; i >= 0; i--)
		{
			if (str[i] == '0')
				str[i] = '\0';
			else break;
			len--;
		}
		if (str[len - 1] == '.')
			str[len - 1] = '\0';
	}	
}

int main()
{
	char a[1000],b[1000];
	while (~scanf("%s%s", a, b))	**************************!!!!
	{
		change(a);
	//	printf("%s\t",a);
		change(b);
	//	printf("%s\n",b);

		if (strcmp(a, b))		//【返回值】若参数s1 和s2 字符串相同则返回0。
			printf("NO\n");
		else
			printf("YES\n");

	}
	return 0;
}