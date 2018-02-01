#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
***************************************************

输入一个英文句子，将每个单词的第一个字母改成大写字母。

gets可以接收空格；可接受回车键之前输入的所有字符，并用'\n'替代 '\0'.回车键不会留在输入缓冲区中
scanf遇到空格、回车和Tab键都会认为输入结束，所有它不能接收空格。
***************************************************
*/
int main()

{
	char str[100];
//	while (scanf("%s", str) != EOF)		//用scanf 输入字符串时空格对他影响很大
	while (gets(str))					//此处不能使用getchar()
	{
		unsigned int len = strlen(str);
		for (int i = 0; i<len; i++)
		{
			if (i == 0)
				str[i] -= 32;
			if (str[i-1] == ' ' && str[i] != ' ')
				str[i] -= 32;

		}

		for (int i = 0; i<len; i++)
		{
			if (i>0 && str[i] < 'a')
				printf("%c", str[i]);
			else
				printf("%c", str[i]);
		}
		printf("\n");			//一直编译出错在这 没有换行
	}
	return 0;
}