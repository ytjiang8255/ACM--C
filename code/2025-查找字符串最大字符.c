#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
****************************************

		对于输入的每个字符串，
		查找其中的最大字母，
		在该字母后面插入字符串“(max)”。

	
	头文件：#include <string.h>

strlen()函数用来计算字符串的长度，其原型为：
    unsigned int strlen (char *s);

【参数说明】s为指定的字符串。
strlen()用来计算指定的字符串s 的长度，不包括结束字符"\0"。

【返回值】返回字符串s 的字符数。

sizeof返回的是变量声明后所占的内存数，
不是实际长度，此外sizeof不是函数，仅仅是一个操作符，strlen()是函数。
****************************************
*/
int main()
{
	char str[100];
	while (scanf("%s",str) != EOF)
	{
		int Index =0;
		for(int i=0;i<strlen(str);i++)
		{
			if(str[Index]<str[i])
				Index = i;
		}
		
		for(int i=0;i<strlen(str);i++)
		{
			printf("%c",str[i]);
			if(str[i] == str[Index])
				printf("(max)");
			
		}
		printf("\n");
	}
	return 0;
}