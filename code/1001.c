#include <stdio.h>

int main(void)
{
	int sum=0,n,i;
	while(scanf("%d",&n) != EOF)	//切记while 循环技巧
	{
		sum = 0;		//清除程序执行中产生的sum 余值的影响
		for (i=0;i <= n ;i++)
		{
			sum += i;
		}
		printf("%d\n\n",sum);
	}
	return 0;
}