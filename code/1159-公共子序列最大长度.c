#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/******************************************************
 给定序列的子序列是具有一些元素（可能没有）的给定序列。
 给定序列X = <x1，x2，...，xm>另一个序列Z = <z1，z2，...，zk>是X的子序列，
 如果存在严格增加的序列<i1，i2，... ，ik> X的索引，使得对于所有j = 1,2，...，k，xij = zj。
 例如，Z = <a，b，f，c>是索引序列<1,2,4,6>的X = <a，b，c，f，b，c>的子序列。 
 给定两个序列X和Y，问题是找到X和Y的最大长度公共子序列的长度。
 程序输入来自文本文件。 文件中的每个数据集包含两个表示给定序列的字符串。 
 这些序列被任何数量的空格分开。 输入数据正确。 对于每组数据，
 程序在标准输出上打印从单独行开始的最大长度公共子序列的长度。

 
 贪心转向动态规划:
F[i][j]=F[i-1][j-1]+1；（a[i]==b[j]）
F[i][j]=max(F[i-1][j],F[i][j-1])(a[i]!=b[j]);
n由于F(i,j)只和F(i-1,j-1), F(i-1,j)和F(i,j-1)有关, 而在计算F(i,j)时, 只要选择一个合适的顺序, 
就可以保证这三项都已经计算出来了, 这样就可以计算出F(i,j). 这样一直推到f(len(a),len(b))就得到所要求的解了
 
****************************************************/

char a[1001], b[1001];
int f[1001][1001],N;
int main()
{
	while (scanf("%s%s", a , b ) != EOF)
	{
		int  a_len, b_len;
		a_len = strlen(a);
		b_len = strlen(b);
		for (int i = 0; i <= a_len; i++)
			f[i][0] = 0;
		for (int i = 0; i <= b_len; i++)
			f[0][i] = 0;

		for (int i = 1; i<=a_len; i++)
		{
			for (int j = 1;j <= b_len; j++)
			{
				if (a[i - 1] == b[j - 1])
					f[i][j] = f[i - 1][j - 1] + 1;
				else
					f[i][j] = f[i - 1][j] > f[i][j - 1] ? f[i - 1][j] : f[i][j - 1];
			}
		}
		printf("%d\n", f[a_len][b_len]);

	}
	return 0;
}

/*	char a[1000],b[1000];
	
	while(scanf("%s%s",a,b)!=EOF)
	{
		int num=0,len=0,a_len,b_len;
		a_len=strlen(a);
		b_len=strlen(b);
		if(a_len<b_len)
			len=b_len;
		else
			len=a_len;
		printf("%d\n",len);
		
		for(int i=0;i<len;i++)
		{
			if(a[i]==b[i])
				num++;
			
		}
		
	}
*/	