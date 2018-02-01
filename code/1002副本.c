#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

#define MAX 1024
char a[MAX], b[MAX], c[MAX];
int len_c; //和的位数
void CaculateAB() //计算a和b
{
	int i, len_a, len_b, len_add, digit_sum, carry;     //digit_sum对应位数的和，carry进位
	len_a = strlen(a);
	len_b = strlen(b);
	len_add = (len_a <= len_b) ? len_a : len_b;
	carry = 0;
	for (i = 0; i<len_add; i++)
	{
		digit_sum = a[len_a - i - 1] - '0' + b[len_b - i - 1] - 48 + carry;
		c[i] = digit_sum % 10 + 48;
		carry = digit_sum / 10;
	}
	if (len_a>len_b)
	{
		for (; i<len_a; i++)
		{
			digit_sum = a[len_a - i - 1] - 48 + carry;
			c[i] = digit_sum % 10 + 48;
			carry = digit_sum / 10;
		}
	}
	else
	{
		for (; i<len_b; i++)
		{
			digit_sum = b[len_b - i - 1] - 48 + carry;
			c[i] = digit_sum % 10 + 48;
			carry = digit_sum / 10;
		}
	}
	if (carry>0) c[i++] = carry + 48;
	len_c = i;
}
int main(void)
{
	int t, i, k;
	scanf("%d", &t);
	for (k = 0; k<t; k++)
	{
		scanf("%s%s", a, b);
		CaculateAB();
		printf("Case %d:\n%s + %s = ", k + 1, a, b);
		//c保存的是和的逆序排列，要逆序输出
		for (i = 0; i<len_c; i++)
		{
			printf("%c", c[len_c - i - 1]);
		}
		printf("\n");
		if (k<t - 1) printf("\n");    //***，这里注意一下不然会Presentation Error
	}
	return 0;
}