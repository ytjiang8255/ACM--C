#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
***************************************************
每个案例由一个由空白分隔的行中的两个十六进制整数A和B组成。
A和B的长度小于15。输入包含几个测试用例，请处理到文件末尾。

long long定义方式可以用于gcc/g++，不受平台限制，但不能用于VC6.0。
__int64是Win32平台编译器64位长整型的定义方式，不能用于Linux。
“%lld”用于Linux i386平台编译器，”%I64d”用于Win32平台编译器。
cout只能用于C++编译，在VC6.0中，cout不支持64位长整型。
***************************************************
*/
int main()
{
	long long a=0, b=0;
	while (scanf("%llX%llX", &a, &b) != EOF)
	{
//		printf("%llX\t%llX\n", a, b);

		if (a + b >= 0)
			printf("%llX\n", (a + b));
		else
			printf("-%llX\n", -(a + b));
	}
	--------------------------------------
	__int64 a = 0, b = 0;
	while (scanf("%I64X%I64X", &a, &b) != EOF)
	{
		//	printf("%llX\t%llX\n", a, b);

		if (a + b >= 0)
			printf("%I64X\n", (a + b));
		else
			printf("-%I64X\n", -(a + b));
	}
	
	return 0;
}