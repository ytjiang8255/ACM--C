#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/*
**************************************************************
设有n个正整数，将它们连成一排组成一个整数，请编程输出其中最大的结果。

strcmp(const char *s1,const char *s2);

当s1<s2时，返回为负数；
当s1==s2时，返回值= 0；
当s1>s2时，返回正数。
即：两个字符串自左向右逐个字符相比（按ASCII值大小相比较），直到出现不同的字符或遇'\0'为止。


char *strcat(char *strDestination,const char *strSource );

功能：函数将字符串str2 连接到str1的末端，并返回指针str1
注：连接前两个字符串的后面都有一个'\0'，连接时将字符串1后面的'\0'去掉，只在新串最后保留一个 '\0'


char *strcpy(char *strDestination,const char *strSource );

功能：复制字符串strSource中的字符到字符串strDestination，包括空值结束符。返回值为指针strDestination。
注：1、“字符数组1”必须写成数组名形式，“字符串2"可以是字符数组名，也可以是一个字符串常量
	2、复制时连同字符串后面的'\0'一起复制到数组1中
	3、不能用赋值语句直接将一个字符串常量或者字符数组直接赋给一个字符数组（同普通变量数组是一样的），而只能用strcpy函数处理。
	4、可以用strcpy函数将字符串2中的前若干个字符复制到字符数组1中去。
**************************************************************
*/


int main()
{
	char* s[100];
	int N;
	while(scanf("%d",&N)!=EOF && N!=0)
	{
		for(int i=0;i<N;i++)
		{
			scanf("%s",s+i);
			
		}
			
			
		
		
	}
	
	return 0;
}