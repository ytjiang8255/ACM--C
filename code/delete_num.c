#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/*
*******************************************************

键盘输入一个高精度的正整数ｎ（<=240位），去掉任意ｓ（s<n）个数字后,
将剩下的数字按原左右次序组成一个新的正整数。
给定ｎ和ｓ，请编程输出最小的新正整数。



功 能： 使用快速排序例程进行排序
头文件：stdlib.h
用 法： void  qsort (void  *base,	 int  elent_num, 	int  elent_width, int (*fcmp)(const void *,const void *));
参数：
1 待排序数组首地址
2 数组中待排序元素数量
3 各元素的占用空间大小
4 指向比较函数的指针，用于确定排序的顺序

*******************************************************
*/
int comp(const void *a, const void *b)
{
	return *(char*)a - *(char*)b;
}




int main()
{
	char s[100], e[100];
	int N, i,sum;
	while (scanf("%s%*c%d",s,&N) != EOF)
	{
		int len = strlen(s);
		qsort(s, len, sizeof (s[0]), comp);
//			printf("%s\n", s);
		
		for (int i = 0; i < len - N; i++)
		//将剩下的数字按原左右次序组成一个新的正整数，然后利用输出的特性强制输出需要的数据
		{
			printf("%c", s[i]);
		}
		
		printf("\n");
	}

	return 0;
}
————————————————————————————————————————————————————————————————————————————————————————————————————————————————
{
	char str[100], new1[100];
	int n, num, tail, head, i;
	while (scanf("%s%d", str, &n) != EOF)
	{
		tail = head = num = i = 1;
		new1[0] = str[0];
		int len = strlen(str);
		for (int i = 1,num=0; i < len , num<n; i++)
		{
			if (str[i] < str[i + 1])
			{
				str[i + 1] = str[i+2];
				new1[i] = str[i];
				len--;
				num++;
			}
			else
			{
				str[i] = str[i + 1];
				new1[i] = str[i];
				len--;
				num++;
			}
		}

		printf("%s\n", new1);
	}

	return 0;
}