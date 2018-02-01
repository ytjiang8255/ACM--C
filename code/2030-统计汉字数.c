#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
***************************************************

统计给定文本文件中汉字的个数。
输入文件首先包含一个整数n，表示测试实例的个数，然后是n段文本。
对于每一段文本，输出其中的汉字的个数，每个测试实例的输出占一行。
[Hint:]从汉字机内码的特点考虑~

汉字内码采用两个字节，一个汉字占两个ASCII字符；
汉字内码最高位为1，ASCII码最高位为0

***************************************************
*/
int main()
{
	int N;
	char str[1000];
	while (scanf("%d%*c", &N) != EOF)
	{
		
		for (int i = 0; i<N; i++)
		{
			int count = 0;
			gets(str);
//			scanf("%s", str);
			int len = strlen(str);
//			for (int j = 0; str[j] !='\0'; j++)
			for (int j = 0; j < len;j++)
			{
				if (str[j] < 0)	count += 1;
		//		else	continue;
			}
			printf("%d\n", count / 2);

		}

	}

	
	return 0;
}