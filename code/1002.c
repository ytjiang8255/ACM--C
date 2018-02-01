/*
输入的第一行包含一个整数T（1 <= T <= 20），
这意味着测试用例数。 然后T行跟随，
每行由两个正整数A和B组成。请注意，整数非常大，
这意味着您不应该使用32位整数来处理它们。 
您可以假设每个整数的长度不会超过1000。


对于每个测试用例，您应该输出两行。 
第一行是“Case＃：”，＃表示测试用例的编号。
第二行是一个方程“A + B = Sum”，Sum表示A + B的结果。
注意方程式中有一些空格。 在两个测试用例之间输出空行。

*/


#include <stdio.h>
#include <string.h>
#define MAX 1024
/*
* char字符与int整数之间通过的转换ascii码
*
* 把char字符型数字转成int数字，因为他们的ascii码值恰好相差48， 
* 因此把char型数字减去48得到int型数据，例如'4'转换成了4 
* '0'的ascii码是48 
*/

int main(void)
{
	char a[MAX] = { 0 }, b[MAX] = { 0 };
	int n, i, j = 1, sum[MAX] = { 0 };
	int alen, blen, len_Max,temp;
	scanf("%d", &n);
	while (n--)
	{
		if (j != 1)
			printf("\n");
		scanf("%s%s", a, b);
		alen = strlen(a);
		blen = strlen(b);
		len_Max = (alen > blen) ? alen : blen;
		for (i = 0; i < len_Max; i++)
			sum[i] = 0;
		temp = len_Max;		//temp 用来输出次数

		for (len_Max; alen > 0 && blen > 0; len_Max--)
		{
			sum[len_Max] += (alen - '0' - 1) + (blen - '0' - 1);
			if (sum[len_Max] / 10)
			{
				sum[len_Max - 1]++;
				sum[len_Max] %= 10;
			}
		}

		while (alen > 0)
		{
			sum[len_Max--] += (a[alen - '0' - 1]);
			if (sum[len_Max+1] / 10)
			{
				sum[len_Max]++;
				sum[len_Max + 1] %= 10;
			}
		}

		while (blen > 0)
		{
			sum[len_Max--] += (b[alen - '0' - 1]);
			if (sum[len_Max+1] / 10)
			{
				sum[len_Max]++;
				sum[len_Max + 1] %= 10;
			}
		}

		printf("Case %d:\n");
		printf("%s + %s = ", a, b);

		for (i = 0; i < temp; i++)
		{
			if (i == 0 && sum[i] == 0)
				i++;
			printf("%d", sum[i]);

		}

		printf("\n");

	}
		
		
		
	
	}
	return 0;
}


