#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
输入中含有一些数据，分别是成对出现的花布条和小饰条，其布条都是用可见ASCII字符表示的，
可见的ASCII字符有多少个，布条的花纹也有多少种花样。花纹条和小饰条不会超过1000个字符长。
如果遇见#字符，则不再进行工作。
输出能从花纹布中剪出的最多小饰条个数，如果一块都没有，那就老老实实输出0，每个结果之间应换行。

abcde a3
aaaaaa  aa
#
--------------
0
3
**/
int main()
{
	char A[1000],b[1000];
	int i,j,k,len_A,len_b,count,count1;
//	while(scanf("%s",A)==EOF)	//不能用EOF EOF返回的是整数-1
	while(scanf("%s%s",A,b))
	{
		if(A[0]=='#')
			break;		//一出现break 则程序就死翘翘了
		count=0;
		len_A=strlen(A);
		len_b=strlen(b);
		for(i=0;i<len_A;i+=len_b)
		{
			count=0;
			for(j=0,k=i;k<i+len_b,j<len_b;k++,j++)
			{
				if(A[k]==b[j])
					count++;
				else
					break;
			}
			if(count==len_b)
				++count1;
		}
		printf("%d\n",count1);	
	}
	return 0;
}