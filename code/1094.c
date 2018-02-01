#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/*
*******************************************************	
		Input contains multiple test cases, 
		and one case one line. 
		Each case starts with an integer N,
		and then N integers follow in the same line. 
*******************************************************
*/
int main(void)
{
	int i, N, a, sum = 0;
	while(scanf("%d",&N) != EOF)
	{
		for (i=0;i<N;i++)
		{
			
			scanf("%d",&a);
			sum += a;
			
		}
		printf("%d\n",sum);
		sum = 0;		
	//sum = 0;[注意！！！]这句代码放while（）代码块里最后和最前都是一样的效果,清除sum余值
	}
	
	return 0;
}